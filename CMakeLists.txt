cmake_minimum_required(VERSION 3.0.0)
project(HardwareMap VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Find the required X11 package
find_package(X11 REQUIRED)

# Check if X11 and Xrandr are available
if (X11_FOUND AND X11_Xrandr_FOUND)
    include_directories(${X11_INCLUDE_DIR})
    link_libraries(${X11_LIBRARIES} ${X11_Xrandr_LIB})
else()
    message(FATAL_ERROR "X11/Xrandr not found!")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find and include libcurl
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

# ... rest of your CMake configuration

find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBUDEV REQUIRED libudev)
include_directories(${LIBUDEV_INCLUDE_DIRS})

# Locate the ALSA library
find_library(ALSA_LIBRARY asound)

# Check if ALSA library is found
if(NOT ALSA_LIBRARY)
    message(FATAL_ERROR "ALSA library not found")
endif()

# When defining your target, link against the found libraries
add_executable(hardware_map main.cpp cpu/cpu.cpp webcam/webcam.cpp memory/memory.cpp ram/ram.cpp display/display.cpp disk/disk.cpp battery/battery.cpp d.cpp wireless/wifi.cpp ethernet/ethernet.cpp bluetooth/bluetooth.cpp keyboard/keyboard.cpp mouse/mouse.cpp touchpad/touchpad.cpp audio/audio.cpp mic/mic.cpp gpu/gpu.cpp sys_info/sys_info.cpp)
target_link_libraries(hardware_map ${X11_LIBRARIES} ${X11_Xrandr_LIB} ${LIBUDEV_LIBRARIES} ${CURL_LIBRARIES} bluetooth ${ALSA_LIBRARY}) 

install(TARGETS hardware_map DESTINATION bin)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
