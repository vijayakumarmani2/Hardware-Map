#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/statvfs.h>

bool get_disk_size(const char* path, unsigned long long& total_size) {
    struct statvfs stat;
    if (statvfs(path, &stat) != 0) {
        std::cerr << "Error getting disk information" << std::endl;
        return false;
    }
    total_size = static_cast<unsigned long long>(stat.f_frsize) * stat.f_blocks;
    return true;
}

std::string readFile_sysInfo(const std::string& filePath) {
    std::ifstream file(filePath);
    std::string content;
    std::getline(file, content);
    return content;
}

std::string getUsernameFromUID(int uid) {
    std::ifstream file("/etc/passwd");
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string user, x, id;
        if (std::getline(iss, user, ':') &&
            std::getline(iss, x, ':') &&
            std::getline(iss, id, ':')) {
            if (std::stoi(id) == uid) {
                return user;
            }
        }
    }
    return "Unknown";
}

std::string getSysModelName() {
    return readFile_sysInfo("/sys/class/dmi/id/product_name");
}

std::string getSysvendorName() {
    return readFile_sysInfo("/sys/class/dmi/id/sys_vendor");
}

std::string getSysvendorUUID() {
    return readFile_sysInfo("/sys/class/dmi/id/product_uuid");
}

void gatherSystemInfo() {
    std::string userName = readFile_sysInfo("/proc/sys/kernel/hostname");
    std::string kernelVersion = readFile_sysInfo("/proc/version");
    int uid = getuid();
   // std::string userName = getUsernameFromUID(uid);
    std::string systemName = getSysvendorName();
    std::string systemModel= getSysModelName();
    std::string systemUUID= getSysvendorUUID();
    

    std::cout << "System Vendor Name: " << systemName << std::endl;
    std::cout << "System Model Name: " << systemModel << std::endl;
    std::cout << "System UUID: " << systemUUID << std::endl;
    std::cout << "Host Name: " << userName << std::endl;
    std::cout << "Kernel Version: " << kernelVersion << std::endl;
    const char* path = "/home";  // You can specify the path to the directory or file system you want to check.

    unsigned long long total_size;
    if (get_disk_size(path, total_size)) {
        std::cout << "Disk Size - /home (GiB): " << total_size / (1024 * 1024 * 1024) << " GiB" << std::endl;
    }
    
   
}

void sys_info() {
    gatherSystemInfo();
   // return 0;
}
