#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <filesystem> 

std::pair<std::string, std::string> get_cpu_freq_info(const std::string& freq_file) {
    std::ifstream file(freq_file);
    if (!file.is_open()) {
        return {"N/A", "N/A"};
    }

    std::string min_freq, max_freq;
    file >> min_freq >> max_freq;
    file.close();

    return {min_freq, max_freq};
}

std::string get_cpu_architecture() {
    std::ifstream cpuinfo_file("/proc/cpuinfo");
    std::string cpuinfo_line;
    while (std::getline(cpuinfo_file, cpuinfo_line)) {
        if (cpuinfo_line.find("flags") != std::string::npos) {
            if (cpuinfo_line.find("lm") != std::string::npos) {
                return "x86_64";
            }
        }
    }
    return "Unknown";
}

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
    if (cpuinfo_data.count("vendor_id"))
        std::cout << "CPU Vendor Name: " << cpuinfo_data.at("vendor_id").front() << std::endl;

    if (cpuinfo_data.count("model name"))
        std::cout << "CPU Model Name: " << cpuinfo_data.at("model name").front() << std::endl;
    
    if (cpuinfo_data.count("cpu cores"))
        std::cout << "CPU Cores: " << cpuinfo_data.at("cpu cores").front() << std::endl;

    std::cout << "CPU(s): " << (cpuinfo_data.count("processor") ? std::to_string(cpuinfo_data.at("processor").size()) : "N/A") << std::endl;
    // Get CPU architecture
    std::string cpu_architecture = get_cpu_architecture();
    std::cout << "CPU Architecture: " << cpu_architecture << std::endl;
    std::cout << "CPU op-mode(s): 32-bit, 64-bit" << std::endl; // Assuming x86_64 architecture
    std::cout << "Byte Order: Little Endian" << std::endl; // Assuming x86_64 architecture
    

    if (cpuinfo_data.count("cpu family"))
        std::cout << "CPU Family: " << cpuinfo_data.at("cpu family").front() << std::endl;

    if (cpuinfo_data.count("model"))
        std::cout << "Model: " << cpuinfo_data.at("model").front() << std::endl;
    
    // Get CPU frequencies
    std::pair<std::string, std::string>  freq_info_base = get_cpu_freq_info("/sys/devices/system/cpu/cpu0/cpufreq/base_frequency");
    std::cout << "CPU Base Frequency: " << freq_info_base.first << " kHz" << std::endl;

    std::pair<std::string, std::string> freq_info_min = get_cpu_freq_info("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_min_freq");
    std::cout << "Minimum CPU Frequency: " << freq_info_min.first << " kHz" << std::endl;

    std::pair<std::string, std::string>  freq_info_max = get_cpu_freq_info("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq");
    std::cout << "Maximum CPU Frequency: " << freq_info_max.first << " kHz" << std::endl;

    if (cpuinfo_data.count("stepping"))
        std::cout << "Stepping: " << cpuinfo_data.at("stepping").front() << std::endl;

    if (cpuinfo_data.count("cache size"))
        std::cout << "Cache Size: " << cpuinfo_data.at("cache size").front() << std::endl;

    if (cpuinfo_data.count("physical id"))
        std::cout << "Physical ID: " << cpuinfo_data.at("physical id").front() << std::endl;

    if (cpuinfo_data.count("siblings"))
        std::cout << "Siblings: " << cpuinfo_data.at("siblings").front() << std::endl;

    if (cpuinfo_data.count("core id"))
        std::cout << "Core ID: " << cpuinfo_data.at("core id").front() << std::endl;
    
    std::cout << "Virtualization: " << get_virtualization() << std::endl;

    if (cpuinfo_data.count("flags"))
        std::cout << "Flags: " << cpuinfo_data.at("flags").front() << std::endl;
    
    auto vulnerabilities = get_vulnerabilities();
    std::cout << "Vulnerabilities: " << std::endl;
    for (const auto &[vuln, status] : vulnerabilities) {
        std::cout << vuln << ": " << status << std::endl;
    }

    
}

void cpu() {
    auto cpuinfo_data = parse_cpuinfo();
    display_cpuinfo(cpuinfo_data);
 //   return 0;
}

