
# Memory Info Tool

This tool provides categorized information about the system's memory by parsing the `/proc/meminfo` file on Linux systems. The details are grouped into sections like General Memory Info, Swap Info, Buffer/Cached Info, and more.

## Prerequisites

- A Linux system (the tool relies on `/proc/meminfo` which is specific to Linux)
- A C++ compiler (e.g., `g++`)

## Compilation & Installation

1. **Compile**:


make


2. **Install**:

To install the tool system-wide (typically, into `/usr/local/bin/`):


sudo make install


3. **Clean Up**:

To remove the compiled binary from the project directory:

make clean

## Usage

Once installed, run the tool anywhere from the terminal:


memory_info_own


The output will display memory details categorized into sections.

## Features

- **General Memory Info**: Displays total, free, and available memory.
- **Swap Info**: Shows total swap, free swap, and cached swap details.
- **Buffer/Cached Info**: Details about buffers, cached memory, reclaimable slab memory, and unreclaimable slab memory.
- **Low vs. High Memory**: Provides details on low and high memory totals and free spaces.
- **Active vs. Inactive Memory**: Shows details on active and inactive memory, further categorized by anonymous and file memory.


