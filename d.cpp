#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

std::string getMonitorVendor(const std::string &edidPath) {
    std::ifstream edidFile(edidPath, std::ios::binary);
    if (!edidFile) {
        return "Error: Unable to open EDID file";
    }

    // Read the EDID binary data (128 bytes)
    std::string edidData((std::istreambuf_iterator<char>(edidFile)), std::istreambuf_iterator<char>());

    // Check if the EDID data is valid
    if (edidData.size() < 128) {
        return "Error: Invalid EDID data";
    }

    // The monitor vendor name is located in bytes 8-17 of the EDID
    std::string vendorName;
    for (int i = 8; i <= 17; ++i) {
        if (isprint(edidData[i])) {
            vendorName += edidData[i];
        }
    }

    return vendorName;
}

void d() {
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Unable to open X display." << std::endl;
        return;
    }

    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);
    XRRScreenResources* resources = XRRGetScreenResources(display, root);

    std::cout << "Connected Monitors:" << std::endl;
    for (int i = 0; i < resources->noutput; ++i) {
        XRROutputInfo* outputInfo = XRRGetOutputInfo(display, resources, resources->outputs[i]);
        if (outputInfo->connection == RR_Connected) {
            std::cout << "Monitor " << i << ": " << outputInfo->name << std::endl;

            // Get the associated CRTC and its information
            RRCrtc crtc = outputInfo->crtc;
            if (crtc != None) {
                XRRCrtcInfo *crtcInfo = XRRGetCrtcInfo(display, resources, crtc);

                if (crtcInfo) {
                    std::cout << "  Resolution: " << crtcInfo->width << "x" << crtcInfo->height << std::endl;

                    // Adjust the EDID path for your system
                    std::ostringstream edidPath;
                    edidPath << "/sys/class/drm/card0-" << outputInfo->name << "/edid";
std::cout << "EDID Path: " << edidPath.str() << std::endl;
                    std::string vendorName = getMonitorVendor(edidPath.str());
                    std::cout << "  Vendor: " << vendorName << std::endl;

                    XRRFreeCrtcInfo(crtcInfo);
                }
            }
        }
        XRRFreeOutputInfo(outputInfo);
    }

    XRRFreeScreenResources(resources);
    XCloseDisplay(display);
}


