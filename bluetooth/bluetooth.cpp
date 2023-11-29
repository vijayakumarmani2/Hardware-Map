#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <sys/ioctl.h>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>

// Function to create a lookup table using the OUI data file
std::map<std::string, std::string> createVendorLookupTable(const std::string& filePath) {
    std::map<std::string, std::string> vendorLookupTable;

    std::ifstream file(filePath);
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') {
            continue; // Skip comments and empty lines
        }

        // Check if the line contains at least 18 characters before extracting substrings
        if (line.size() >= 18) {
            std::string oui = line.substr(0, 8); // Extract the OUI part

            // Remove hyphens and spaces from the OUI for comparison
            oui.erase(std::remove_if(oui.begin(), oui.end(), ::isspace), oui.end());
            oui.erase(std::remove_if(oui.begin(), oui.end(), [](char c){ return c == '-'; }), oui.end());

            // Find the position of "base 16" in the line
            size_t base16Pos = line.find("base 16");
            if (base16Pos != std::string::npos) {
                // Extract the vendor name (starting from "base 16" and removing leading/trailing spaces)
                std::string vendor = line.substr(base16Pos + 8); // Add 7 to skip "base 16" and following spaces
                vendor = vendor.substr(vendor.find_first_not_of(" \t")); // Remove leading spaces
                vendor = vendor.substr(0, vendor.find_last_not_of(" \t") + 1); // Remove trailing spaces
                vendorLookupTable[oui] = vendor;
            }
        }
    }

    return vendorLookupTable;
}

void bluetooth() {
    int dev_id = hci_get_route(NULL);
    if (dev_id < 0) {
        std::cerr << "No Bluetooth adapter found" << std::endl;
        return;
    }

    int sock = hci_open_dev(dev_id);
    if (sock < 0) {
        std::cerr << "Could not open device: " << strerror(errno) << std::endl;
        return;
    }

    struct hci_dev_info dev_info;
    if (ioctl(sock, HCIGETDEVINFO, &dev_info) < 0) {
        std::cerr << "Could not get device info: " << strerror(errno) << std::endl;
        close(sock);
        return;
    }

    char addr[19] = {0};
    ba2str(&dev_info.bdaddr, addr);

    std::cout << "Bluetooth Device Address: " << addr << std::endl;
    std::cout << "Device Name: " << dev_info.name << std::endl;

    char oui[9];
    strncpy(oui, addr, 8);
    oui[8] = '\0';

    // Replace colons with hyphens in the OUI
    for (int i = 0; i < 8; i++) {
        if (oui[i] == ':') {
            oui[i] = '-';
        }
    }

    std::string ouiWithoutHyphensAndSpaces = oui;
    ouiWithoutHyphensAndSpaces.erase(std::remove_if(ouiWithoutHyphensAndSpaces.begin(), ouiWithoutHyphensAndSpaces.end(), ::isspace), ouiWithoutHyphensAndSpaces.end());
    ouiWithoutHyphensAndSpaces.erase(std::remove_if(ouiWithoutHyphensAndSpaces.begin(), ouiWithoutHyphensAndSpaces.end(), [](char c){ return c == '-'; }), ouiWithoutHyphensAndSpaces.end());

    std::string ouiFilePath = "/usr/share/misc/oui.txt";
    std::map<std::string, std::string> vendorLookupTable = createVendorLookupTable(ouiFilePath);
    //std::cout << "Extracted OUI: " << oui << std::endl;

    auto it = vendorLookupTable.find(ouiWithoutHyphensAndSpaces);
    if (it != vendorLookupTable.end()) {
        std::cout << "Vendor: " << it->second << std::endl;
    } else {
        std::cout << "Vendor not found" << std::endl;
        // Debugging: Print the content of the vendorLookupTable
        for (const auto& entry : vendorLookupTable) {
            std::cout << "OUI: " << entry.first << " Vendor: " << entry.second << std::endl;
        }
    }
    close(sock);
}


