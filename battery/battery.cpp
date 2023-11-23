#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> 
#include <filesystem>
namespace fs = std::filesystem;

using namespace std;
// Function to read a value from a file
string readValueFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open file- " << filename << endl;
       // exit(1);
    }
    string value;
    file >> value;
    return value;
}

void battery() {
    string batteryPath = "/sys/class/power_supply/BAT0/"; // Change this to match your system's battery path

    string statusFile = batteryPath + "status";
    string capacityFile = batteryPath + "capacity";
    string voltageFile = batteryPath + "voltage_now";
    string currentFile = batteryPath + "current_now";
    string manufacturerFile = batteryPath + "manufacturer";
    string modelNameFile = batteryPath + "model_name";
    string technologyFile = batteryPath + "technology";
    //string healthFile = batteryPath + "health";

    string status = readValueFromFile(statusFile);
    string capacity = readValueFromFile(capacityFile);
    string voltageMicrovolts = readValueFromFile(voltageFile);

    string manufacturer = readValueFromFile(manufacturerFile);
    string modelName = readValueFromFile(modelNameFile);
    string technology = readValueFromFile(technologyFile);

    // Dynamically discover files in the battery directory
    for (const auto& entry : fs::directory_iterator(batteryPath)) {
        string fileName = entry.path().filename().string();
        string filePath = entry.path().string();

        if (fileName.find(currentFile) != string::npos) {
            string currentMicroamperes = readValueFromFile(filePath);
        }else if (fileName.find("power_now") != string::npos) {
            string currentMicroamperes = readValueFromFile(filePath);
        }
    }
    string currentMicroamperes = readValueFromFile(currentFile);
  //  string health = readValueFromFile(healthFile);

    // Convert voltage from microvolts to volts
    double voltageVolts = stod(voltageMicrovolts) / 1000000.0; // Convert to volts

    // Convert current from microamperes to amperes
    double currentAmperes = stod(currentMicroamperes) / 1000000.0; // Convert to amperes
    
    cout << "Battery Vendor: " << manufacturer << endl;
    cout << "Battery Model Name: " << modelName << endl;
    cout << "Battery Technology: " << technology << endl;
    cout << "Battery Status: " << status << endl;
    cout << "Battery Capacity: " << capacity << "%" << endl;
    cout << "Battery Voltage: " << fixed << setprecision(2) << voltageVolts << " volts" << endl;
    cout << "Battery Current: " << fixed << setprecision(2) << currentAmperes << " amperes" << endl;
  //  cout << "Battery Health: " << health << endl;
    
    
    
    

    //return 0;
}
