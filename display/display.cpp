#include <iostream>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

void display() {
    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Unable to open X display." << std::endl;
        //return 1;
    }

    int screen = DefaultScreen(display);
    Window root = RootWindow(display, screen);
    XRRScreenResources* resources = XRRGetScreenResources(display, root);

    std::cout << "Connected Monitors:" << std::endl;
    for (int i = 0; i < resources->noutput; ++i) {
        XRROutputInfo* outputInfo = XRRGetOutputInfo(display, resources, resources->outputs[i]);
        if (outputInfo->connection == RR_Connected && outputInfo->ncrtc > 0) {
            XRRCrtcInfo *crtcInfo = XRRGetCrtcInfo(display, resources, outputInfo->crtc);
            XRRModeInfo *modeInfo = NULL;
            for (int m = 0; m < resources->nmode; m++) {
                if (resources->modes[m].id == crtcInfo->mode) {
                    modeInfo = &resources->modes[m];
                    break;
                }
            }

            if (modeInfo) {
                std::cout << "Monitor " << i << ": " << outputInfo->name << std::endl;
                std::cout << "Resolution: " << modeInfo->width << "x" << modeInfo->height << std::endl;
                std::cout << "Refresh Rate: " << modeInfo->dotClock * 1000.0 / (modeInfo->hTotal * modeInfo->vTotal) << " Hz" << std::endl;
            }

            XRRFreeCrtcInfo(crtcInfo);
        }
        XRRFreeOutputInfo(outputInfo);
    }

    XRRFreeScreenResources(resources);
    XCloseDisplay(display);

   // return 0;
}

