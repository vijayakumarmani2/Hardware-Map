/*******************************************************************************
 * Company: Zoho Corporation
 * Author: Vijayakumar Mani
 * File: audio.cpp
 * Description: to retrive audio information from linux system
 * Date: 
 * 
 * Copyright (c) 2023 Zoho Corporation. All rights reserved.
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <alsa/asoundlib.h>
#include <dirent.h>

// Function to look up the vendor name from the pci.ids file
std::string getVendorName(const std::string& vendorId) {
    std::ifstream file("/usr/share/misc/pci.ids");
    std::string line;
    while (std::getline(file, line)) {
        // Check if the line is a comment
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Check if the line is a vendor line (it should start with a hexadecimal number)
        if (line.size() >= 4 && isxdigit(line[0]) && isxdigit(line[1]) && isxdigit(line[2]) && isxdigit(line[3])) {
            // Extract the vendor ID from the line
            std::string currentVendorId = line.substr(0, 4);

            // Check if this is the vendor we are looking for
            if (currentVendorId == vendorId) {
                // Extract the vendor name from the line
                size_t pos = line.find(' ');
                if (pos != std::string::npos) {
                    return line.substr(pos + 1);
                }
            }
        }
    }
    return "Unknown Vendor";
}

std::string getDeviceName(const std::string& vendorId, const std::string& deviceId) {
    std::ifstream pciIdsFile("/usr/share/misc/pci.ids");
    std::string line;
    bool deviceSection = false;

    while (std::getline(pciIdsFile, line)) {
        // Check if the line is a comment
        if (line.empty() || line[0] == '#') {
            continue;
        }

        // Check if the line starts with the vendor ID
        if (line.find(vendorId) == 0) {
            // Mark that we are now in the device section for this vendor
            deviceSection = true;
            continue;
        }

        // If we're in a device section and the line is not empty, it's a device name
        if (deviceSection && !line.empty() && line[0] != '\t') {
            // Extract the device ID and name
            size_t pos = line.find(' ');
            if (pos != std::string::npos) {
                std::string currentDeviceId = line.substr(0, pos);
                if (currentDeviceId == deviceId) {
                    return line.substr(pos + 1);
                }
            }
        }

        // If we're in a device section and the line is empty, it means we've reached the end of the device section
        if (deviceSection && line.empty()) {
            break;
        }
    }

    return "Unknown Device";
}


void getDetailedInfo(int cardNum) {
    // Construct the path to the sysfs directory for the sound card
    std::ostringstream pathStream;
    pathStream << "/sys/class/sound/card" << cardNum << "/device/";
    std::string devicePath = pathStream.str();

    // Read vendor, device, subvendor, and subdevice IDs from sysfs
    std::ifstream vendorFile(devicePath + "vendor");
    std::ifstream deviceFile(devicePath + "device");
    std::ifstream subVendorFile(devicePath + "subsystem_vendor");
    std::ifstream subDeviceFile(devicePath + "subsystem_device");

    std::string vendor, device, subVendor, subDevice;
    std::getline(vendorFile, vendor);
    std::getline(deviceFile, device);
    std::getline(subVendorFile, subVendor);
    std::getline(subDeviceFile, subDevice);

    // Read the driver name from the sysfs
    DIR* dir = opendir((devicePath + "driver/module/drivers").c_str());
    if (dir) {
        struct dirent* entry;
        while ((entry = readdir(dir)) != nullptr) {
            if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                std::cout << "Driver: " << entry->d_name << std::endl;
                break;
            }
        }
        closedir(dir);
    }

    // Print the gathered information
    std::cout << "Vendor: " << vendor << std::endl;
    std::cout << "Device: " << device << std::endl;
    std::cout << "SubVendor: " << subVendor << std::endl;
    std::cout << "SubDevice: " << subDevice << std::endl;
}


void audio() {
    int cardNum = -1;
    while (snd_card_next(&cardNum) >= 0 && cardNum >= 0) {
        snd_ctl_t *ctl;
        char name[32];
        sprintf(name, "hw:%d", cardNum);
        if (snd_ctl_open(&ctl, name, 0) >= 0) {
            snd_ctl_card_info_t *info;
            snd_ctl_card_info_alloca(&info);
            if (snd_ctl_card_info(ctl, info) >= 0) {
                std::cout << "Card " << cardNum << ": " << snd_ctl_card_info_get_name(info) << " [" << snd_ctl_card_info_get_id(info) << "]" << std::endl;
                getDetailedInfo(cardNum);
                // Construct the path to the sysfs directory for the sound card
                std::ostringstream pathStream;
                pathStream << "/sys/class/sound/card" << cardNum << "/device/vendor";
                std::string vendorPath = pathStream.str();

                // Read vendor ID from sysfs
                std::ifstream vendorFile(vendorPath);
                std::string vendorId;
                if (std::getline(vendorFile, vendorId)) {
                    // Remove the "0x" prefix if present
                    if (vendorId.compare(0, 2, "0x") == 0 || vendorId.compare(0, 2, "0X") == 0) {
                        vendorId = vendorId.substr(2);
                    }
                    std::cout <<"Vendor Name: " << getVendorName(vendorId) << std::endl;
                }

                // Print vendorId for debugging
                std::cout << "vendorId (from sysfs): " << vendorId << std::endl;

                // Get the device ID from sysfs
                std::ostringstream deviceIdPathStream;
                deviceIdPathStream << "/sys/class/sound/card" << cardNum << "/device/device";
                std::string deviceIdPath = deviceIdPathStream.str();
                std::ifstream deviceIdFile(deviceIdPath);
                std::string deviceId;
                if (std::getline(deviceIdFile, deviceId)) {
                    if (deviceId.compare(0, 2, "0x") == 0 || deviceId.compare(0, 2, "0X") == 0) {
                        deviceId = deviceId.substr(2);
                    }
                }

                // Print deviceId for debugging
                std::cout << "Device ID (from sysfs): " << deviceId << std::endl;

                std::cout <<"Device Name: " << getDeviceName(vendorId, deviceId) << std::endl;
            }
            snd_ctl_close(ctl);
        }
    }
}
