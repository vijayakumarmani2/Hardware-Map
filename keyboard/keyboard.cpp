#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <dirent.h>

// Function to read a file and return its contents as a string
std::string readFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// Function to check if a string contains a specific substring
bool containsSubstring(const std::string& str, const std::string& substr) {
    return str.find(substr) != std::string::npos;
}

// Function to find the input device number for the keyboard
int findKeyboardInputNumber() {
    DIR* inputDir = opendir("/sys/class/input");
    if (!inputDir) {
        std::cerr << "Error opening /sys/class/input directory." << std::endl;
        return -1;
    }

    dirent* entry;
    while ((entry = readdir(inputDir))) {
       // std::cout << "containsSubstring: " << entry->d_type << std::endl;
        if (containsSubstring(entry->d_name, "event")) {
            std::string deviceName = readFile("/sys/class/input/" + std::string(entry->d_name) + "/device/name");
         //   std::cout << "deviceName: " << deviceName << std::endl;
            if (containsSubstring(deviceName, "keyboard")) {
                closedir(inputDir);
                return std::stoi(entry->d_name + 5); // Extract the input number from "eventX"
            }
        }
    }

    closedir(inputDir);
    return -1; // Keyboard not found
}

// Function to extract and print keyboard information
void extractKeyboardInfo(int inputNumber) {
    if (inputNumber == -1) {
        std::cerr << "Keyboard not found." << std::endl;
        return;
    }

    std::string inputPath = "/sys/class/input/event" + std::to_string(inputNumber) + "/device/";


    std::string model = readFile(inputPath + "/name");
    std::string vendorId = readFile(inputPath + "/id/vendor");
    std::string deviceId = readFile(inputPath + "/id/product");
    std::string driver = readFile(inputPath + "/device/driver/description");
    std::string deviceDes = readFile(inputPath + "/device/description");

    // Print the extracted information
    std::cout << "Hardware Class: keyboard\n" << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Vendor id: " << vendorId << std::endl;
    std::cout << "Device id : " << deviceId << std::endl;
    std::cout << "Driver: " << driver << std::endl;
    std::cout << "Device description: " << deviceDes<< std::endl;

    

}

void keyboard() {
     // Find the input device number for the keyboard
    int inputNumber = findKeyboardInputNumber();

    extractKeyboardInfo(inputNumber);

   // return 0;
}
