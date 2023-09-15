# Hardware-Map

The Hardware Map Tool is a command-line application that provides comprehensive information about your system's hardware specifications. You can use this tool to retrieve information about the CPU, webcam, memory, RAM, display, battery, and disk.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Supported Commands](#supported-commands)
- [Example Usage](#example-usage)
- [License](#license)

## Installation

Follow these steps to build and install the Hardware Map Tool:

### Prerequisites

- CMake (version 3.0 or higher)
- Make
- C++ compiler (GCC or Clang)

### Clone the Repository


git clone <repository_url>
cd hardware-map-tool


### Build the Application


mkdir build
cd build
cmake ..
make


### Install the Tool (Optional)

If you want to install the tool system-wide (recommended), use the following command:


sudo make install


This step is optional but allows you to run the tool from anywhere in your terminal without specifying the path to the binary.

## Usage

Once you have installed the Hardware Map Tool (or if you prefer to run it from the build directory), you can use the following commands to retrieve hardware information:

### Supported Commands

- **CPU Information:**

   
   hardware_map cpu
   

- **Webcam Information:**

   
   hardware_map webcam
   

- **Memory Information:**

   `
   hardware_map memory
   

- **RAM Information:**

   
   hardware_map ram
   

- **Display Information:**

   
   hardware_map display
   

- **Battery Information:**

   
   hardware_map battery
   

- **Disk Information:**

   
   hardware_map disk
   

- **All Hardware Information:**

   
   hardware_map all
   

The tool will display detailed information about the specified hardware component.

## Example Usage


# Get information about the CPU
hardware_map cpu

# Get information about all hardware components
hardware_map all
