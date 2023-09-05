

# C++ Implementation of own lscpu

This project is a C++ implementation of the Linux utility `lscpu`, which displays information about the system's CPU architecture.

## Features

- Fetches CPU details similar to the `lscpu` utility.
- Provides virtualization, cache, NUMA, and vulnerability details.
- Written in C++ for Linux systems.

## Dependencies

- A modern C++ compiler with C++17 support.
- Linux OS with support for `/proc/cpuinfo` and `/sys/devices/system/cpu/vulnerabilities/`.

## Compilation

Using the provided Makefile, you can easily compile and run the program:

Compile the code:


make


Run the program:


make run


## Installation

After compiling, you can install the binary for system-wide usage:


sudo make install


This will copy the `cpp_own_lscpu` binary to `/usr/local/bin`, allowing you to run it from any location in the terminal.

To uninstall:


sudo make uninstall


## Usage

After installation, use the program as:


lscpu_own



