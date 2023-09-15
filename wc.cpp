#include <iostream>
#include <fstream>
#include <map>
#include <libudev.h>
#include <unistd.h>

// Function to load usb.ids into a map
std::map<std::string, std::string> loadUsbIds(const std::string &path) {
    std::map<std::string, std::string> usbIds;
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open " << path << std::endl;
        return usbIds;
    }

    std::string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#' || line[0] == '\t') continue; // Skip comments, empty lines, and product lines

        std::string id = line.substr(0, 4);
        std::string name = line.substr(6);
       // std::cerr << "name:  " << name << std::endl;
        usbIds[id] = name;
    }

    file.close();
    return usbIds;
}


void wc() {
    struct udev *udev;
    struct udev_enumerate *enumerate;
    struct udev_list_entry *devices, *dev_list_entry;

    // Initialize the udev object
    udev = udev_new();
    if (!udev) {
        std::cerr << "Failed to initialize udev" << std::endl;
        //return 1;
    }

std::string vendorName;
const char *vendorId;
// char cwd[1024];
// if (getcwd(cwd, sizeof(cwd)) != NULL) {
    //std::string fullPath = std::string(cwd) + "/../usb.ids"; 
     auto usbIds = loadUsbIds("/home/vijay-16033/Documents/Repos_handler/Hardware_Map/usbmap/usb.ids");
      // Create a list of devices in the 'video4linux' subsystem
    enumerate = udev_enumerate_new(udev);
    udev_enumerate_add_match_subsystem(enumerate, "video4linux");
    udev_enumerate_scan_devices(enumerate);
    devices = udev_enumerate_get_list_entry(enumerate);

    // For each device...
    udev_list_entry_foreach(dev_list_entry, devices) {
        const char* path = udev_list_entry_get_name(dev_list_entry);
        struct udev_device* dev = udev_device_new_from_syspath(udev, path);

        // Navigate to the parent USB device to get details
        struct udev_device* parent = udev_device_get_parent_with_subsystem_devtype(dev, "usb", "usb_device");
        if (parent) {
            vendorId = udev_device_get_sysattr_value(parent, "idVendor");
            const char *productId = udev_device_get_sysattr_value(parent, "idProduct");

             vendorName = usbIds[std::string(vendorId)]; // Look up the vendor name using the vendor ID

            std::cout << "Vendor: usb " << vendorId << " \"" << (vendorName.empty() ? "Unknown" : vendorName) << "\"" << std::endl;
            std::cout << "Device: usb " << productId << " \"" << (productId ? productId : "Unknown") << "\"" << std::endl; // Using productId directly since we're not mapping device names
            std::cout << "-------------------------------" << std::endl;
        }

        udev_device_unref(dev);
    }
// } else {
//     std::cerr << "Error getting current working directory" << std::endl;
// }

   

    // Cleanup
    udev_enumerate_unref(enumerate);
    udev_unref(udev);

   // return 0;
}
