#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

namespace fs = std::filesystem;

// Function to read and extract information from a file
std::string readFromFile(const std::string &filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return "";
    }

    std::string data;
    std::getline(file, data);
    file.close();

    return data;
}

// Function to get disk information
void getDiskInfo(const std::string &diskName) {
    // Paths to the disk information in the /sys filesystem
    std::string sysPath = "/sys/class/block/" + diskName;

    // Read disk model, vendor, and serial number from /sys
    std::string model = readFromFile(sysPath + "/device/model");
    std::string vendor = readFromFile(sysPath + "/device/vendor");
    std::string serial = readFromFile(sysPath + "/device/serial");

    // Read disk size from /sys
    std::string sizePath = sysPath + "/size";
    std::ifstream sizeFile(sizePath);
    if (sizeFile.is_open()) {
        unsigned long long size;
        sizeFile >> size;
        sizeFile.close();
        std::cout << "Disk Name: " << diskName << std::endl;
        std::cout << "Vendor: " << vendor << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Serial Number: " << serial << std::endl;
        std::cout << "Size (bytes): " << size * 512 << std::endl; // Size is in 512-byte sectors
        std::cout << "-----------------------------" << std::endl;
    }
}

void disk() {
    // List of disks in the /sys/class/block directory
    std::vector<std::string> diskList;
    for (const auto &entry : fs::directory_iterator("/sys/class/block")) {
        diskList.push_back(entry.path().filename());
    }

    // Get information for each disk
    for (const std::string &disk : diskList) {
        getDiskInfo(disk);
    }

   // return 0;
}
