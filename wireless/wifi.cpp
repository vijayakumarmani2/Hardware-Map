#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <cstring>
#include <curl/curl.h>
#include <sys/stat.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>



// Function to get hardware address (MAC address)
std::string getMACAddress(const std::string& interfaceName) {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return "N/A";
    }

    struct ifreq ifr;
    strncpy(ifr.ifr_name, interfaceName.c_str(), IFNAMSIZ);

    if (ioctl(sock, SIOCGIFHWADDR, &ifr) == 0) {
        close(sock);
        unsigned char* mac = reinterpret_cast<unsigned char*>(ifr.ifr_hwaddr.sa_data);
        char macAddress[18];
        snprintf(macAddress, sizeof(macAddress), "%02x:%02x:%02x:%02x:%02x:%02x",
                 mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
        return macAddress;
    } else {
        close(sock);
        return "N/A";
    }
}

// Function to get the first wireless interface name found on the system
std::string getWirelessInterfaceName() {
    // Open a socket to retrieve interface names
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        return "";
    }

    struct ifreq ifr;
    struct ifconf ifc;
    char buffer[1024];

    ifc.ifc_len = sizeof(buffer);
    ifc.ifc_buf = buffer;
    if (ioctl(sock, SIOCGIFCONF, &ifc) == -1) {
        perror("ioctl");
        close(sock);
        return "";
    }

    struct ifreq* it = ifc.ifc_req;
    const struct ifreq* const end = it + (ifc.ifc_len / sizeof(struct ifreq));

    while (it != end) {
        if (strcmp(it->ifr_name, "lo") != 0) { // Exclude loopback interface
            // Check if this is a wireless interface
            if (ioctl(sock, SIOCGIFFLAGS, it) != -1) {
                if ((it->ifr_flags & IFF_UP) && (it->ifr_flags & IFF_RUNNING)) {
                    close(sock);
                    return std::string(it->ifr_name);
                }
            }
        }
        ++it;
    }

    close(sock);
    return "";
}

// Callback function to write HTTP response data to a string
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

// Function to get WiFi hardware vendor details based on MAC address
std::string getVendorDetails(const std::string& macAddress) {
    std::string vendorDetails;
    
    // Construct the URL for the MAC address lookup API
    std::string apiUrl = "https://macvendors.com/query/" + macAddress;

    // Initialize libcurl
    CURL* curl = curl_easy_init();
    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

        // Set callback function to receive the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &vendorDetails);

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "Error while fetching data from the MAC address lookup service: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up libcurl
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Error initializing libcurl." << std::endl;
    }

    return vendorDetails;
}

// Function to get WiFi driver details
std::string getWifiDriverDetails(const std::string& interfaceName) {
    std::string driverDetails;
    std::string driverPath = "/sys/class/net/" + interfaceName + "/device/driver/module";

    // Check if the driver path exists
    struct stat buffer;
    if (stat(driverPath.c_str(), &buffer) == 0) {
        char driverBuffer[256];
        ssize_t bytesRead;

        // Read the driver name from the symlink
        if ((bytesRead = readlink(driverPath.c_str(), driverBuffer, sizeof(driverBuffer) - 1)) != -1) {
            driverBuffer[bytesRead] = '\0';
            driverDetails = driverBuffer;
        } else {
            driverDetails = "N/A";
        }
    } else {
        driverDetails = "N/A";
    }

    return driverDetails;
}

// Function to read a file line by line and return the lines as a vector of strings
std::vector<std::string> readFileLines(const std::string& filename) {
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

// Function to extract WiFi information from /proc/net/wireless
bool extractWiFiInfoFromProcNetWireless(const std::string& interfaceName, std::string& speed, std::string& frequency, std::string& signalLevel, std::string& noiseLevel, std::string& signalToNoiseRatio) {
    std::vector<std::string> lines = readFileLines("/proc/net/wireless");
    
    // Find the section corresponding to the given interface
    bool foundInterface = false;
    for (const std::string& line : lines) {
        if (line.find(interfaceName) != std::string::npos) {
            foundInterface = true;
        }
        if (foundInterface) {
            // Split the line into tokens
            std::istringstream iss(line);
            std::vector<std::string> tokens{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
            
            // Check if the line contains the relevant information
            if (tokens.size() >= 3 && tokens[0] == interfaceName + ":") {
                speed = tokens[1];
                frequency = tokens[2];
                signalLevel = tokens[3];
                noiseLevel = tokens[4];
                signalToNoiseRatio = tokens[5];
                return true;
            }
        }
    }
    
    return false;
}

void wifi() {
    std::string interfaceName = getWirelessInterfaceName();

    if (interfaceName.empty()) {
        std::cerr << "No active wireless interface found." << std::endl;
       // return 1;
    }

    // Get and display MAC address
    std::string macAddress = getMACAddress(interfaceName);
    std::cout << "Hardware Class: network interface" << std::endl;
    std::cout << "Device File: " << interfaceName << std::endl;
    std::cout << "HW Address: " << macAddress << std::endl;
    std::cout << "Permanent HW Address: " << macAddress << std::endl;

    // Get and display vendor details
    std::string vendorDetails = getVendorDetails(macAddress);
    if (!vendorDetails.empty()) {
        std::cout << "WiFi Vendor Details: " << vendorDetails << std::endl;
    } else {
        std::cerr << "Unable to retrieve WiFi vendor details." << std::endl;
    }

    // Get and display WiFi driver details
    std::string wifiDriverDetails = getWifiDriverDetails(interfaceName);
    std::cout << "WiFi Driver Details: " << wifiDriverDetails << std::endl;

    // Get and display WiFi speed and frequency information
    std::string speed, frequency, signalLevel, noiseLevel, signalToNoiseRatio;

    // Get WiFi information from /proc/net/wireless
    bool infoFound = extractWiFiInfoFromProcNetWireless(interfaceName, speed, frequency, signalLevel, noiseLevel, signalToNoiseRatio);

    if (infoFound) {
        std::cout << "WiFi Interface: " << interfaceName << std::endl;
        std::cout << "Speed: " << speed << " Mbps" << std::endl;
        std::cout << "Frequency: " << frequency << " GHz" << std::endl;
        std::cout << "Signal Level: " << signalLevel << " dBm" << std::endl;
        std::cout << "Noise Level: " << noiseLevel << " dBm" << std::endl;
        std::cout << "Signal-to-Noise Ratio: " << signalToNoiseRatio << " dB" << std::endl;
    } else {
        std::cerr << "WiFi information not found for interface " << interfaceName << std::endl;
    }

   // return 0;
}
