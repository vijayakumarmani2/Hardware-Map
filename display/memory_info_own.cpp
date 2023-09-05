#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
    std::ifstream file("/proc/meminfo");
    if (!file) {
        std::cerr << "Failed to open /proc/meminfo.\n";
        return 1;
    }

    std::map<std::string, std::string> meminfo;
    std::string line;
    while (std::getline(file, line)) {
        size_t separator = line.find(':');
        if (separator != std::string::npos) {
            std::string key = line.substr(0, separator);
            std::string value = line.substr(separator + 1);
            meminfo[key] = value;
        }
    }

    // Categorized display
    std::cout << "=== General Memory Info ===\n";
    std::cout << "Total: " << meminfo["MemTotal"] << "\n";
    std::cout << "Free: " << meminfo["MemFree"] << "\n";
    std::cout << "Available: " << meminfo["MemAvailable"] << "\n";

    std::cout << "\n=== Swap Info ===\n";
    std::cout << "Total: " << meminfo["SwapTotal"] << "\n";
    std::cout << "Free: " << meminfo["SwapFree"] << "\n";
    std::cout << "Cached: " << meminfo["SwapCached"] << "\n";

    std::cout << "\n=== Buffer/Cached Info ===\n";
    std::cout << "Buffers: " << meminfo["Buffers"] << "\n";
    std::cout << "Cached: " << meminfo["Cached"] << "\n";
    std::cout << "SReclaimable: " << meminfo["SReclaimable"] << "\n";
    std::cout << "SUnreclaim: " << meminfo["SUnreclaim"] << "\n";

    std::cout << "\n=== Low vs. High Memory ===\n";
    std::cout << "LowTotal: " << meminfo["LowTotal"] << "\n";
    std::cout << "LowFree: " << meminfo["LowFree"] << "\n";
    std::cout << "HighTotal: " << meminfo["HighTotal"] << "\n";
    std::cout << "HighFree: " << meminfo["HighFree"] << "\n";

    std::cout << "\n=== Active vs. Inactive Memory ===\n";
    std::cout << "Active: " << meminfo["Active"] << "\n";
    std::cout << "Inactive: " << meminfo["Inactive"] << "\n";
    std::cout << "Active(anon): " << meminfo["Active(anon)"] << "\n";
    std::cout << "Inactive(anon): " << meminfo["Inactive(anon)"] << "\n";
    std::cout << "Active(file): " << meminfo["Active(file)"] << "\n";
    std::cout << "Inactive(file): " << meminfo["Inactive(file)"] << "\n";

    return 0;
}

