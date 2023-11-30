/*******************************************************************************
 * Company: Zoho Corporation
 * Author: Vijayakumar Mani
 * File: ethernet.cpp
 * Description: to retrive ethernet information from linux system
 * Date: 
 * 
 * Copyright (c) 2023 Zoho Corporation. All rights reserved.
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

// Function to read a file line by line and return the lines as a vector of strings
std::vector<std::string> readFileLines_eth(const std::string& filename) {
    std::vector<std::string> lines;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    return lines;
}

// Function to find the active Ethernet interface
std::string findActiveEthernetInterface() {
    std::string activeInterface;
    for (const auto& entry : fs::directory_iterator("/sys/class/net")) {
        const std::string& interfaceName = entry.path().filename();
        // Exclude loopback and virtual interfaces
        if (interfaceName != "lo" && interfaceName.find("vir") == std::string::npos) {
            std::string carrierPath = "/sys/class/net/" + interfaceName + "/carrier";
            std::vector<std::string> carrierLines = readFileLines_eth(carrierPath);
            if (!carrierLines.empty() && carrierLines[0] == "1") {
                // The interface is active
                activeInterface = interfaceName;
                break;
            }
        }
    }
    return activeInterface;
}


// Function to extract Ethernet information from /sys/class/net
bool extractEthernetInfo(const std::string& interfaceName, std::string& speed, std::string& duplexMode, std::string& macAddress) {
    std::string interfacePath = "/sys/class/net/" + interfaceName + "/";
    
    // Read speed
    std::vector<std::string> speedLines = readFileLines_eth(interfacePath + "speed");
    if (!speedLines.empty()) {
        speed = speedLines[0];
    } else {
        return false;
    }

    // Read duplex mode
    std::vector<std::string> duplexLines = readFileLines_eth(interfacePath + "duplex");
    if (!duplexLines.empty()) {
        duplexMode = duplexLines[0];
    } else {
        return false;
    }

    // Read MAC address
    std::vector<std::string> addressLines = readFileLines_eth(interfacePath + "address");
    if (!addressLines.empty()) {
        macAddress = addressLines[0];
    } else {
        return false;
    }

    return true;
}

void ethernet() {
    // Find the active Ethernet interface
    std::string interfaceName = findActiveEthernetInterface();
    std::string speed, duplexMode, macAddress;

    if (!interfaceName.empty()) {
        // Get Ethernet information
        bool infoFound = extractEthernetInfo(interfaceName, speed, duplexMode, macAddress);

        if (infoFound) {
            std::cout << "Ethernet Interface: " << interfaceName << std::endl;
            std::cout << "Speed: " << speed << " Mbps" << std::endl;
            std::cout << "Duplex Mode: " << duplexMode << std::endl;
            std::cout << "MAC Address: " << macAddress << std::endl;
        } else {
            std::cerr << "Ethernet information not found for interface " << interfaceName << std::endl;
        }
    } else {
        std::cerr << "No active Ethernet interface found." << std::endl;
    }

   // return 0;
}
