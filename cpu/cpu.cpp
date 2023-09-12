#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <filesystem> 

std::map<std::string, std::vector<std::string>> parse_cpuinfo() {
    std::map<std::string, std::vector<std::string>> cpuinfo_data;
    std::ifstream file("/proc/cpuinfo");
    if (!file.is_open()) {
        std::cerr << "Error opening /proc/cpuinfo" << std::endl;
        return cpuinfo_data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key, value;
        if (std::getline(iss, key, ':') && std::getline(iss, value)) {
            key = key.substr(0, key.find_last_not_of(" \t\n\r\f\v") + 1);
            value = value.substr(value.find_first_not_of(" \t\n\r\f\v"));

            cpuinfo_data[key].push_back(value);
        }
    }

    file.close();
    return cpuinfo_data;
}

std::string get_virtualization() {
    // This is a basic check and may not be comprehensive.
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("vmx") != std::string::npos) return "VT-x";
        if (line.find("svm") != std::string::npos) return "AMD-V";
    }
    return "Unknown";
}

std::map<std::string, std::string> get_vulnerabilities() {
    std::map<std::string, std::string> vulnerabilities;
    for (const auto &entry : std::filesystem::directory_iterator("/sys/devices/system/cpu/vulnerabilities/")) {
        std::ifstream file(entry.path());
        std::string vulnerability_status;
        std::getline(file, vulnerability_status);
        vulnerabilities[entry.path().filename()] = vulnerability_status;
    }
    return vulnerabilities;
}
void display_cpuinfo(const std::map<std::string, std::vector<std::string>>& cpuinfo_data) {
    std::cout << "Architecture: " << (cpuinfo_data.count("processor") ? std::to_string(cpuinfo_data.at("processor").size()) : "N/A") << std::endl;
    std::cout << "CPU op-mode(s): 32-bit, 64-bit" << std::endl; // Assuming x86_64 architecture
    std::cout << "Byte Order: Little Endian" << std::endl; // Assuming x86_64 architecture
     std::cout << "Virtualization: " << get_virtualization() << std::endl;
     
    if (cpuinfo_data.count("vendor_id"))
        std::cout << "Vendor ID: " << cpuinfo_data.at("vendor_id").front() << std::endl;

    if (cpuinfo_data.count("cpu family"))
        std::cout << "CPU Family: " << cpuinfo_data.at("cpu family").front() << std::endl;

    if (cpuinfo_data.count("model"))
        std::cout << "Model: " << cpuinfo_data.at("model").front() << std::endl;

    if (cpuinfo_data.count("model name"))
        std::cout << "Model Name: " << cpuinfo_data.at("model name").front() << std::endl;

    if (cpuinfo_data.count("stepping"))
        std::cout << "Stepping: " << cpuinfo_data.at("stepping").front() << std::endl;

    if (cpuinfo_data.count("cpu MHz"))
        std::cout << "Frequency: " << cpuinfo_data.at("cpu MHz").front() << " MHz" << std::endl;

    if (cpuinfo_data.count("cache size"))
        std::cout << "Cache Size: " << cpuinfo_data.at("cache size").front() << std::endl;

    if (cpuinfo_data.count("physical id"))
        std::cout << "Physical ID: " << cpuinfo_data.at("physical id").front() << std::endl;

    if (cpuinfo_data.count("siblings"))
        std::cout << "Siblings: " << cpuinfo_data.at("siblings").front() << std::endl;

    if (cpuinfo_data.count("core id"))
        std::cout << "Core ID: " << cpuinfo_data.at("core id").front() << std::endl;

    if (cpuinfo_data.count("cpu cores"))
        std::cout << "CPU Cores: " << cpuinfo_data.at("cpu cores").front() << std::endl;

    if (cpuinfo_data.count("flags"))
        std::cout << "Flags: " << cpuinfo_data.at("flags").front() << std::endl;
    
    auto vulnerabilities = get_vulnerabilities();
    std::cout << "Vulnerabilities: " << std::endl;
    for (const auto &[vuln, status] : vulnerabilities) {
        std::cout << "  " << vuln << ": " << status << std::endl;
    }
}

void cpu() {
    auto cpuinfo_data = parse_cpuinfo();
    display_cpuinfo(cpuinfo_data);
 //   return 0;
}

