
# RAM memory info

A simple program to parse and display information from the Direct Media Interface (DMI) table on Linux systems.

## Features

- Displays detailed information about system memory from the DMI table.
- Parses DMI types 16 (Physical Memory Array), 17 (Memory Device), and 19 (Memory Array Mapped Address).

## Prerequisites

- A Linux system with access to `/sys/firmware/dmi/tables/DMI`.
- GCC for compiling the program.

## Installation

1. Clone the repository or download the source code.
2. Navigate to the directory containing the source code.
3. Compile the program using the provided `Makefile`:
   
   make
   `
4. Install the program:
   
   sudo make install
   

## Usage

After installation, you can run the program with:

RAM_info_own

## Uninstallation

To uninstall the program:

sudo make uninstall





