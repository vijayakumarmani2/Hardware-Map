#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <alsa/asoundlib.h>

std::string getVendorName_mic(const std::string& vendorId);
std::string getDeviceName_mic(const std::string& vendorId, const std::string& deviceId);

void mic() {
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

                // Check if the card has microphone controls
                if (snd_ctl_pcm_next_device(ctl, &cardNum) >= 0) {
                    // Get the vendor ID from sysfs
                    std::ostringstream vendorPathStream;
                    vendorPathStream << "/sys/class/sound/card" << cardNum << "/device/vendor";
                    std::string vendorPath = vendorPathStream.str();
                    std::ifstream vendorFile(vendorPath);
                    std::string vendorId;
                    if (std::getline(vendorFile, vendorId)) {
                        if (vendorId.compare(0, 2, "0x") == 0 || vendorId.compare(0, 2, "0X") == 0) {
                            vendorId = vendorId.substr(2);
                        }
                    }

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

                std::cout << "Vendor ID: " << vendorId << ", Vendor Name: " << getVendorName_mic(vendorId) << std::endl;
                std::cout << "Device ID: " << deviceId << ", Device Name: " << getDeviceName_mic(vendorId, deviceId) << std::endl;
            }
            snd_ctl_close(ctl);
        }
    }
    }
   // return 0;
}

// Function to look up the vendor name from the pci.ids file
std::string getVendorName_mic(const std::string& vendorId) {
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

std::string getDeviceName_mic(const std::string& vendorId, const std::string& deviceId) {
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
