/*******************************************************************************
 * Company: Zoho Corporation
 * Author: Vijayakumar Mani
 * File: touchpad.cpp
 * Description: to retrive touchpad information from linux system
 * Date: 
 * 
 * Copyright (c) 2023 Zoho Corporation. All rights reserved.
 ******************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <dirent.h>

// Function to read a file and return its contents as a string
std::string readFile_touchpad(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Function to check if a string contains a specific substring
bool containsSubstring_touchpad(const std::string& str, const std::string& substr) {
    return str.find(substr) != std::string::npos;
}

// Function to find the input device number for the keyboard
int findtouchpadInputNumber() {
    DIR* inputDir = opendir("/sys/class/input");
    if (!inputDir) {
        std::cerr << "Error opening /sys/class/input directory." << std::endl;
        return -1;
    }

    dirent* entry;
    while ((entry = readdir(inputDir))) {
       // std::cout << "containsSubstring: " << entry->d_type << std::endl;
        if (containsSubstring_touchpad(entry->d_name, "event")) {
            std::string deviceName = readFile_touchpad("/sys/class/input/" + std::string(entry->d_name) + "/device/name");
         //  std::cout << "deviceName: " << deviceName << " event: " << entry->d_name << std::endl;
            if (containsSubstring_touchpad(deviceName, "Touchpad")) {
                closedir(inputDir);
                return std::stoi(entry->d_name + 5); // Extract the input number from "eventX"
            }
        }
    }

    closedir(inputDir);
    return -1; // Keyboard not found
}

// Function to extract and print keyboard information
void extracttouchpadInfo(int inputNumber) {
    if (inputNumber == -1) {
        std::cerr << "touchpad not found." << std::endl;
        return;
    }

    std::string inputPath = "/sys/class/input/event" + std::to_string(inputNumber) + "/device/";


    std::string model = readFile_touchpad(inputPath + "/name");
    std::string vendorId = readFile_touchpad(inputPath + "/id/vendor");
    std::string deviceId = readFile_touchpad(inputPath + "/id/product");
    std::string driver = readFile_touchpad(inputPath + "/device/driver/description");
    std::string deviceDes = readFile_touchpad(inputPath + "/device/description");

    // Print the extracted information
    std::cout << "Hardware Class: touchpad" << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Vendor id: " << vendorId << std::endl;
    std::cout << "Device id : " << deviceId << std::endl;
    std::cout << "Driver: " << driver << std::endl;
    std::cout << "Device description: " << deviceDes<< std::endl;

    

}

void touchpad() {
     // Find the input device number for the keyboard
    int inputNumber = findtouchpadInputNumber();

    extracttouchpadInfo(inputNumber);

   // return 0;
}
