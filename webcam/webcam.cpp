/*******************************************************************************
 * Company: Zoho Corporation
 * Author: Vijayakumar Mani
 * File: webcam.cpp
 * Description: to retrive webcam information from linux system
 * Date: 
 * 
 * Copyright (c) 2023 Zoho Corporation. All rights reserved.
 ******************************************************************************/

#include <fcntl.h>
#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <map>
#include <libudev.h>
#include <unistd.h>
#include <set>
#include <cstdint>

// Function to fetch details using udevadm
std::string execCmd(const char* cmd) {
    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(cmd, "r");
    if (!pipe) throw std::runtime_error("popen() failed!");
    try {
        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        throw;
    }
    pclose(pipe);
    return result;
}
std::string fourccToString(uint32_t fourcc) {
    std::string res;
    for (int i = 0; i < 4; ++i) {
        res += static_cast<char>(fourcc & 0xFF);
        fourcc >>= 8;
    }
    return res;
}

std::vector<std::string> capabilitiesToString(unsigned int caps) {
    std::vector<std::string> capabilities;
    
    if (caps & V4L2_CAP_VIDEO_CAPTURE) {
        capabilities.push_back("Video Capture");
    }
    if (caps & V4L2_CAP_VIDEO_OUTPUT) {
        capabilities.push_back("Video Output");
    }
    if (caps & V4L2_CAP_VIDEO_OVERLAY) {
        capabilities.push_back("Video Overlay");
    }
    if (caps & V4L2_CAP_VBI_CAPTURE) {
        capabilities.push_back("VBI Capture");
    }
    if (caps & V4L2_CAP_VBI_OUTPUT) {
        capabilities.push_back("VBI Output");
    }
    if (caps & V4L2_CAP_SLICED_VBI_CAPTURE) {
        capabilities.push_back("Sliced VBI Capture");
    }
    if (caps & V4L2_CAP_SLICED_VBI_OUTPUT) {
        capabilities.push_back("Sliced VBI Output");
    }
    if (caps & V4L2_CAP_RDS_CAPTURE) {
        capabilities.push_back("RDS Capture");
    }
    if (caps & V4L2_CAP_VIDEO_OUTPUT_OVERLAY) {
        capabilities.push_back("Video Output Overlay");
    }
    if (caps & V4L2_CAP_HW_FREQ_SEEK) {
        capabilities.push_back("Hardware Frequency Seek");
    }
    if (caps & V4L2_CAP_RDS_OUTPUT) {
        capabilities.push_back("RDS Output");
    }
    if (caps & V4L2_CAP_TUNER) {
        capabilities.push_back("Tuner");
    }
    if (caps & V4L2_CAP_AUDIO) {
        capabilities.push_back("Audio");
    }
    if (caps & V4L2_CAP_RADIO) {
        capabilities.push_back("Radio");
    }
    if (caps & V4L2_CAP_MODULATOR) {
        capabilities.push_back("Modulator");
    }
    if (caps & V4L2_CAP_READWRITE) {
        capabilities.push_back("Read/Write");
    }
    if (caps & V4L2_CAP_ASYNCIO) {
        capabilities.push_back("Async I/O");
    }
    if (caps & V4L2_CAP_STREAMING) {
        capabilities.push_back("Streaming");
    }
    if (caps & V4L2_CAP_EXT_PIX_FORMAT) {
        capabilities.push_back("Extended Pix Format");
    }
    if (caps & V4L2_CAP_SDR_CAPTURE) {
        capabilities.push_back("SDR Capture");
    }
    if (caps & V4L2_CAP_SDR_OUTPUT) {
        capabilities.push_back("SDR Output");
    }
    if (caps & V4L2_CAP_META_CAPTURE) {
        capabilities.push_back("Metadata Capture");
    }
    if (caps & V4L2_CAP_META_OUTPUT) {
        capabilities.push_back("Metadata Output");
    }
    if (caps & V4L2_CAP_TOUCH) {
        capabilities.push_back("Touch");
    }
    
    return capabilities;
}

// Function to load usb.ids into a map
std::map<std::string, std::string> loadUsbIds_1(const std::string &path) {
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


//main function
void webcam() {

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
std::set<std::string> printedVendors;
// char cwd[1024];
// if (getcwd(cwd, sizeof(cwd)) != NULL) {
    //std::string fullPath = std::string(cwd) + "/../usb.ids"; 
     auto usbIds = loadUsbIds_1("/usr/share/misc/usb.ids");
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

           // std::cout << "Vendor: usb " << vendorId << " \"" << (vendorName.empty() ? "Unknown" : vendorName) << "\"" << std::endl;
           // std::cout << "Device: usb " << productId << " \"" << (productId ? productId : "Unknown") << "\"" << std::endl; // Using productId directly since we're not mapping device names
           // std::cout << "-------------------------------" << std::endl;
        }

        udev_device_unref(dev);
    }
// } else {
//     std::cerr << "Error getting current working directory" << std::endl;
// }

   

    // Cleanup
    udev_enumerate_unref(enumerate);
    udev_unref(udev);


    struct v4l2_queryctrl queryctrl;
    int fd = open("/dev/video0", O_RDWR); // Open the video device file
    if (fd == -1) {
        std::cerr << "Cannot open video device" << std::endl;
       // return 1;
    }

    // Query device capabilities
    struct v4l2_capability cap;
    if (ioctl(fd, VIDIOC_QUERYCAP, &cap) == -1) {
        std::cerr << "Error querying device capabilities" << std::endl;
        //return 1;
    }

    // Print some information
    std::cout << "Driver Name: " << cap.driver << std::endl;
    std::cout << "Vendor Name: " << (vendorName.empty() ? "Unknown" : vendorName) << std::endl;
    std::cout << "Card Type: " << cap.card << std::endl;
    std::cout << "Bus Info: " << cap.bus_info << std::endl;
    std::cout << "Driver Version: " << ((cap.version >> 16) & 0xFF) << "." << ((cap.version >> 8) & 0xFF) << "." << (cap.version & 0xFF) << std::endl;
    std::vector<std::string> capStrings = capabilitiesToString(cap.capabilities);

std::cout << "Capabilities: ";
for (const auto& cap : capStrings) {
    std::cout << cap << ", ";
}
std::cout << std::endl;
    

//    // Fetch available controls
//     struct v4l2_queryctrl queryctrl;
//     queryctrl.id = V4L2_CID_BASE;

//     std::cout << "\nUser Controls" << std::endl;
//     while (ioctl(fd, VIDIOC_QUERYCTRL, &queryctrl) == 0) {
//         std::cout << queryctrl.name << ": Min " << queryctrl.minimum << ", Max " << queryctrl.maximum << std::endl;

//         // Change control values using VIDIOC_S_CTRL
//         // if (queryctrl.id == V4L2_CID_BRIGHTNESS) { // This is just an example; you can check for any control
//         //     struct v4l2_control control;
//         //     control.id = V4L2_CID_BRIGHTNESS;
//         //     control.value = queryctrl.maximum; // Set to max value as an example

//         //     if (ioctl(fd, VIDIOC_S_CTRL, &control) == -1) {
//         //         std::cerr << "Failed to set control " << queryctrl.name << std::endl;
//         //     } else {
//         //         std::cout << "Successfully set " << queryctrl.name << " to " << control.value << std::endl;
//         //     }
//         // }

//         queryctrl.id++;
//     }

    // Supported format Info
    struct v4l2_fmtdesc fmtdesc;
    fmtdesc.index = 0;
    fmtdesc.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
    //std::cout << "\n" << std::endl;
    while (ioctl(fd, VIDIOC_ENUM_FMT, &fmtdesc) == 0) {
    std::cout << "Supported format: " << fmtdesc.description << std::endl;
    fmtdesc.index++;
}

    // Video Input
    int input;
    if (ioctl(fd, VIDIOC_G_INPUT, &input) == -1) {
        std::cerr << "Error retrieving video input" << std::endl;
    } else {
        std::cout << "Video input : " << input << std::endl;
    }

    // Format Video Capture
    struct v4l2_format format;
    format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

    if (ioctl(fd, VIDIOC_G_FMT, &format) == -1) {
        std::cerr << "Error retrieving video format" << std::endl;
    } else {
        std::cout << "Format Video Capture:" << std::endl;
        std::cout << "Width/Height: " << format.fmt.pix.width << "/" << format.fmt.pix.height << std::endl;
        std::cout << "Pixel Format: '" << fourccToString(format.fmt.pix.pixelformat) << "'" << std::endl;
        std::cout << "Field: " << format.fmt.pix.field << std::endl;
        std::cout << "Bytes per Line: " << format.fmt.pix.bytesperline << std::endl;
        std::cout << "Size Image: " << format.fmt.pix.sizeimage << std::endl;
        std::cout << "Colorspace: " << format.fmt.pix.colorspace << std::endl;
    }


struct v4l2_cropcap cropcap;
struct v4l2_selection selection;
struct v4l2_streamparm streamparm;

memset(&cropcap, 0, sizeof(cropcap));
cropcap.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

if (ioctl(fd, VIDIOC_CROPCAP, &cropcap) == 0) {
    printf("Crop Capability Video Capture:\n");
    printf("Bounds      : Left %d, Top %d, Width %d, Height %d\n", cropcap.bounds.left, cropcap.bounds.top, cropcap.bounds.width, cropcap.bounds.height);
    printf("Default     : Left %d, Top %d, Width %d, Height %d\n", cropcap.defrect.left, cropcap.defrect.top, cropcap.defrect.width, cropcap.defrect.height);
    printf("Pixel Aspect: %d/%d\n", cropcap.pixelaspect.numerator, cropcap.pixelaspect.denominator);
}

memset(&selection, 0, sizeof(selection));
selection.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
selection.target = V4L2_SEL_TGT_CROP_DEFAULT;

if (ioctl(fd, VIDIOC_G_SELECTION, &selection) == 0) {
    printf("Selection Video Capture: crop_default, Left %d, Top %d, Width %d, Height %d, Flags: %d\n", selection.r.left, selection.r.top, selection.r.width, selection.r.height, selection.flags);
}

selection.target = V4L2_SEL_TGT_CROP_BOUNDS;

if (ioctl(fd, VIDIOC_G_SELECTION, &selection) == 0) {
    printf("Selection Video Capture: crop_bounds, Left %d, Top %d, Width %d, Height %d, Flags: %d\n", selection.r.left, selection.r.top, selection.r.width, selection.r.height, selection.flags);
}

memset(&streamparm, 0, sizeof(streamparm));
streamparm.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;

if (ioctl(fd, VIDIOC_G_PARM, &streamparm) == 0) {
    printf("Streaming Parameters Video Capture:\n");
    printf("Capabilities     : timeperframe\n");
    printf("Frames per second: %.3f (%d/%d)\n", (double)streamparm.parm.capture.timeperframe.denominator / (double)streamparm.parm.capture.timeperframe.numerator, streamparm.parm.capture.timeperframe.denominator, streamparm.parm.capture.timeperframe.numerator);
    printf("Read buffers     : %d\n", streamparm.parm.capture.readbuffers);
}


struct v4l2_querymenu querymenu;

memset(&queryctrl, 0, sizeof(queryctrl));

printf("User Controls:\n");

for (queryctrl.id = V4L2_CID_BASE;
     queryctrl.id < V4L2_CID_LASTP1;
     queryctrl.id++) {
    if (ioctl(fd, VIDIOC_QUERYCTRL, &queryctrl) == 0) {
        if (queryctrl.flags & V4L2_CTRL_FLAG_DISABLED)
            continue;

        printf("%s 0x%08x (%s)\t: min=%d max=%d step=%d default=%d value=%d\n",
               queryctrl.name, queryctrl.id,
               (queryctrl.type == V4L2_CTRL_TYPE_INTEGER) ? "int" : 
               (queryctrl.type == V4L2_CTRL_TYPE_BOOLEAN) ? "bool" :
               (queryctrl.type == V4L2_CTRL_TYPE_MENU) ? "menu" : "unknown",
               queryctrl.minimum, queryctrl.maximum,
               queryctrl.step, queryctrl.default_value, 0 /* replace with fetched value */);

        if (queryctrl.type == V4L2_CTRL_TYPE_MENU) {
            memset(&querymenu, 0, sizeof(querymenu));
            querymenu.id = queryctrl.id;
            for (querymenu.index = queryctrl.minimum;
                 querymenu.index <= queryctrl.maximum;
                 querymenu.index++) {
                if (ioctl(fd, VIDIOC_QUERYMENU, &querymenu) == 0) {
                    printf("%d: %s\n", querymenu.index, querymenu.name);
                }
            }
        }
    }
}

// For extended controls: V4L2_CID_CAMERA_CLASS_BASE, V4L2_CID_CAMERA_CLASS, etc.
printf("Camera Controls\n");

for (queryctrl.id = V4L2_CID_CAMERA_CLASS_BASE;
     queryctrl.id < V4L2_CID_CAMERA_CLASS; 
     queryctrl.id++) {
    if (ioctl(fd, VIDIOC_QUERYCTRL, &queryctrl) == 0) {
        if (queryctrl.flags & V4L2_CTRL_FLAG_DISABLED)
            continue;

        printf("%s 0x%08x (%s)\t: min=%d max=%d step=%d default=%d value=%d\n",
               queryctrl.name, queryctrl.id,
               (queryctrl.type == V4L2_CTRL_TYPE_INTEGER) ? "int" : 
               (queryctrl.type == V4L2_CTRL_TYPE_BOOLEAN) ? "bool" :
               (queryctrl.type == V4L2_CTRL_TYPE_MENU) ? "menu" : "unknown",
               queryctrl.minimum, queryctrl.maximum,
               queryctrl.step, queryctrl.default_value, 0 /* replace with fetched value */);

        if (queryctrl.type == V4L2_CTRL_TYPE_MENU) {
            memset(&querymenu, 0, sizeof(querymenu));
            querymenu.id = queryctrl.id;
            for (querymenu.index = queryctrl.minimum;
                 querymenu.index <= queryctrl.maximum;
                 querymenu.index++) {
                if (ioctl(fd, VIDIOC_QUERYMENU, &querymenu) == 0) {
                    printf("\t\t\t%d: %s\n", querymenu.index, querymenu.name);
                }
            }
        }
    }
}


    close(fd);
   // return 0;
}
