// #include <iostream>
// #include <fstream>
// #include <string>

// // Function to read a specific file in sysfs and return its contents as a string
// std::string readSysfsFile(const std::string& filePath) {
//     std::ifstream file(filePath);
//     if (!file.is_open()) {
//         std::cerr << "Failed to open " << filePath << std::endl;
//         return "";
//     }

//     std::string content;
//     std::getline(file, content);
//     file.close();

//     return content;
// }

// void gpu() {
//     const std::string sysfsPath = "/sys/class/drm/card0/device"; // Adjust the path as needed for your system

//     std::string vendor = readSysfsFile(sysfsPath + "/vendor");
//     std::string device = readSysfsFile(sysfsPath + "/device");

//     if (!vendor.empty() && !device.empty()) {
//         std::cout << "GPU Vendor: " << vendor << std::endl;
//         std::cout << "GPU Device: " << device << std::endl;
//     } else {
//         std::cerr << "Failed to retrieve GPU information from sysfs" << std::endl;
//     }

//   //  return 0;
// }


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>

// Function to read a specific file in sysfs and return its contents as a string
std::string readSysfsFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Failed to open " << filePath << std::endl;
        return "";
    }

    std::string content;
    std::getline(file, content);
    file.close();

    return content;
}

// Function to parse the pci.ids database and store vendor and device names
// Function to parse the pci.ids database and store vendor and device names
std::unordered_map<std::string, std::string> parsePciIds() {
    std::unordered_map<std::string, std::string> pciIdMap;

    std::ifstream file("/usr/share/misc/pci.ids"); // Adjust the path as needed
    if (!file.is_open()) {
        std::cerr << "Failed to open pci.ids database" << std::endl;
        return pciIdMap;
    }

    std::string line;
    std::string currentVendorId;

    while (std::getline(file, line)) {
        if (line.empty()) {
            // Skip empty lines
            continue;
        } else if (line[0] != '\t') {
            // Vendor line
            currentVendorId = line.substr(0, 4);
        } else if (!currentVendorId.empty()) {
            // Device line with a known vendor
            std::string deviceId = line.substr(1, 4);
            std::string deviceName = line.substr(6);

            // Store the vendor and device name in the map
            std::string vendorDeviceId = currentVendorId + ":" + deviceId;
            pciIdMap[vendorDeviceId] = deviceName;

            // Debug print: Print each entry as it's added to the map
            //std::cout << "Added to pciIdMap: " << vendorDeviceId << " - " << deviceName << std::endl;
        }
    }

    file.close();

    return pciIdMap;
}

// Function to look up the vendor name from the pci.ids file
std::string getVendorName_mic1(const std::string& vendorId) {
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

std::string getDeviceName_mic1(const std::string& vendorId, const std::string& deviceId) {
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
        if (deviceSection && !line.empty() && line != " ") {
            // Extract the device ID and name
            size_t pos = line.find(' ');
            if (pos != std::string::npos) {
               std::string newLine;

    // Iterate through each character in the original line
    for (char c : line) {
        // Check if the character is not a blank space
        if (c != '\t') {
            // Append the non-blank character to the new line
            newLine += c;
        }
    }
                std::string currentDeviceId = newLine.substr(0, 4);
               //  std::cout << " Device: " << currentDeviceId << std::endl;
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
void gpu() {
    const std::string sysfsPath = "/sys/class/drm/card0/device"; // Adjust the path as needed for your system

    std::string vendorId = readSysfsFile(sysfsPath + "/vendor");
    std::string deviceId = readSysfsFile(sysfsPath + "/device");

    // Remove "0x" prefix from vendorId and deviceId
    if (!vendorId.empty() && !deviceId.empty() && vendorId.substr(0, 2) == "0x" && deviceId.substr(0, 2) == "0x") {
        vendorId = vendorId.substr(2);
        deviceId = deviceId.substr(2);
    }
    std::cout << "Vendor ID: " << vendorId << std::endl;
    std::cout << "Device ID: " << deviceId << std::endl;
    std::cout << "GPU Vendor Name: " << getVendorName_mic1(vendorId) << std::endl;
    std::cout << "GPU Device Name: " << getDeviceName_mic1(vendorId, deviceId) << std::endl;

    // if (!vendorId.empty() && !deviceId.empty()) {
    //     std::unordered_map<std::string, std::string> pciIdMap = parsePciIds();

    //     std::string vendorDeviceId = vendorId + ":" + deviceId;

    // //     auto it = pciIdMap.find(vendorDeviceId);
    //     if (it != pciIdMap.end()) {
    //         std::cout << "GPU Vendor: " << it->first << " (" << it->second << ")" << std::endl;
    //     } else {
    //         std::cerr << "Failed to map GPU ID to vendor and device names" << std::endl;
    //     }

    //      // Print the entire pciIdMap
    //    // std::cout << "PCI ID Map:" << std::endl;
    //   //  for (const auto& entry : pciIdMap) {
    //   //      std::cout << entry.first << " - " << entry.second << std::endl;
    //   //  }
    // } else {
    //     std::cerr << "Failed to retrieve GPU information from sysfs" << std::endl;
    // }


   // return 0;
}
