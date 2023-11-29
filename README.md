# Hardware-Map

The Hardware Map Tool is a application that provides comprehensive information about your system's hardware specifications. It includes both a command-line interface for quick access and a graphical user interface (GUI) for a more user-friendly experience. You can use this tool to retrieve information about the CPU, webcam, memory, RAM, display, battery, disk, wifi, ethernet, bluetooth, keyboard, touchpad, audio,mic and basic system info.

## Main Objectives

1. **Detailed Hardware Information:**
   
   This tool provides detailed hardware information for a system at the click of a button. For example, by clicking the "battery" button, users can view all related battery details.

2. **Download Feature:**
   
   The tool offers a convenient download feature. When users click the "download" button, they receive a .txt file containing comprehensive hardware specifications of their system.

3. **Comparison Capability:**
   
   One of the standout features is the comparison capability. By clicking the "compare" button, users are prompted to select two or more files from their File Explorer. After the selection, the tool displays a summary of the comparison, highlighting any differences with distinct colors in a dialog panel.

4. **Record Differences with Download Comparison:**
   
   For users who wish to keep a record of these differences, there is a "Download Comparison" button. When clicked, it generates an .html file with the comparison results for easy reference.

## Table of Contents
- [Installation](#installation)
- [Usage](#usage)
- [Command Line Interface (CLI)](#command-line-interface-(CLI))
- [Graphical User Interface (GUI)](#graphical-user-interface-(GUI))
- [Example Usage](#example-usage)

## Installation

To install the Hardware Map Tool and GUI, follow these simple steps:

### Prerequisites:

- CMake (version 3.0 or higher)
- Make
- C++ compiler (GCC or Clang)
- Python 3

### Clone the Repository:

    git clone https://github.com/vijayakumarmani2/Hardware-Map.git
    cd Hardware-Map

### Run the Install Script:

    sudo ./install.sh


The install.sh script will handle the installation of necessary packages for both the command line tool and the GUI and also will the build the tool on your system. Once the script completes, the Hardware Map Tool will be set up as a desktop application.

Note: You may be prompted to enter your password during the installation process.
Usage


Once installed, you can use the Hardware Map Tool in two ways:

## Command Line Interface (CLI)

Use the following commands to retrieve hardware information:

   - **CPU Information:**

         hardware_map cpu

   - **Webcam Information:**

         hardware_map webcam

   ... (other hardware components)

   - **All Hardware Information:**
 
         hardware_map all

## Graphical User Interface (GUI)

The GUI provides a user-friendly way to interact with the Hardware Map Tool. To launch the GUI, run:

    hardware_map_gui


In the GUI, you can click on specific buttons (e.g., "Battery," "Compare") to retrieve hardware information or perform comparisons.


## Example Usage

### Get information about the CPU using the command line
     hardware_map cpu

### Launch the GUI for a more interactive experience
     hardware_map_gui

Feel free to explore the various buttons in the GUI to access different hardware details and features.

