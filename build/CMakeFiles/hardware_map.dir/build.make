# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vijay-16033/Documents/Repos_handler/Hardware_Map

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vijay-16033/Documents/Repos_handler/Hardware_Map/build

# Include any dependencies generated for this target.
include CMakeFiles/hardware_map.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/hardware_map.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/hardware_map.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hardware_map.dir/flags.make

CMakeFiles/hardware_map.dir/main.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/main.cpp.o: ../main.cpp
CMakeFiles/hardware_map.dir/main.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/hardware_map.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/main.cpp.o -MF CMakeFiles/hardware_map.dir/main.cpp.o.d -o CMakeFiles/hardware_map.dir/main.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/main.cpp

CMakeFiles/hardware_map.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/main.cpp > CMakeFiles/hardware_map.dir/main.cpp.i

CMakeFiles/hardware_map.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/main.cpp -o CMakeFiles/hardware_map.dir/main.cpp.s

CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o: ../cpu/cpu.cpp
CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o -MF CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o.d -o CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/cpu/cpu.cpp

CMakeFiles/hardware_map.dir/cpu/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/cpu/cpu.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/cpu/cpu.cpp > CMakeFiles/hardware_map.dir/cpu/cpu.cpp.i

CMakeFiles/hardware_map.dir/cpu/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/cpu/cpu.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/cpu/cpu.cpp -o CMakeFiles/hardware_map.dir/cpu/cpu.cpp.s

CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o: ../webcam/webcam.cpp
CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o -MF CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o.d -o CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/webcam/webcam.cpp

CMakeFiles/hardware_map.dir/webcam/webcam.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/webcam/webcam.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/webcam/webcam.cpp > CMakeFiles/hardware_map.dir/webcam/webcam.cpp.i

CMakeFiles/hardware_map.dir/webcam/webcam.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/webcam/webcam.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/webcam/webcam.cpp -o CMakeFiles/hardware_map.dir/webcam/webcam.cpp.s

CMakeFiles/hardware_map.dir/memory/memory.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/memory/memory.cpp.o: ../memory/memory.cpp
CMakeFiles/hardware_map.dir/memory/memory.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/hardware_map.dir/memory/memory.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/memory/memory.cpp.o -MF CMakeFiles/hardware_map.dir/memory/memory.cpp.o.d -o CMakeFiles/hardware_map.dir/memory/memory.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/memory/memory.cpp

CMakeFiles/hardware_map.dir/memory/memory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/memory/memory.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/memory/memory.cpp > CMakeFiles/hardware_map.dir/memory/memory.cpp.i

CMakeFiles/hardware_map.dir/memory/memory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/memory/memory.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/memory/memory.cpp -o CMakeFiles/hardware_map.dir/memory/memory.cpp.s

CMakeFiles/hardware_map.dir/ram/ram.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/ram/ram.cpp.o: ../ram/ram.cpp
CMakeFiles/hardware_map.dir/ram/ram.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/hardware_map.dir/ram/ram.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/ram/ram.cpp.o -MF CMakeFiles/hardware_map.dir/ram/ram.cpp.o.d -o CMakeFiles/hardware_map.dir/ram/ram.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/ram/ram.cpp

CMakeFiles/hardware_map.dir/ram/ram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/ram/ram.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/ram/ram.cpp > CMakeFiles/hardware_map.dir/ram/ram.cpp.i

CMakeFiles/hardware_map.dir/ram/ram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/ram/ram.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/ram/ram.cpp -o CMakeFiles/hardware_map.dir/ram/ram.cpp.s

CMakeFiles/hardware_map.dir/display/display.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/display/display.cpp.o: ../display/display.cpp
CMakeFiles/hardware_map.dir/display/display.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/hardware_map.dir/display/display.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/display/display.cpp.o -MF CMakeFiles/hardware_map.dir/display/display.cpp.o.d -o CMakeFiles/hardware_map.dir/display/display.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/display/display.cpp

CMakeFiles/hardware_map.dir/display/display.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/display/display.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/display/display.cpp > CMakeFiles/hardware_map.dir/display/display.cpp.i

CMakeFiles/hardware_map.dir/display/display.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/display/display.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/display/display.cpp -o CMakeFiles/hardware_map.dir/display/display.cpp.s

CMakeFiles/hardware_map.dir/wc.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/wc.cpp.o: ../wc.cpp
CMakeFiles/hardware_map.dir/wc.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/hardware_map.dir/wc.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/wc.cpp.o -MF CMakeFiles/hardware_map.dir/wc.cpp.o.d -o CMakeFiles/hardware_map.dir/wc.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/wc.cpp

CMakeFiles/hardware_map.dir/wc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/wc.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/wc.cpp > CMakeFiles/hardware_map.dir/wc.cpp.i

CMakeFiles/hardware_map.dir/wc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/wc.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/wc.cpp -o CMakeFiles/hardware_map.dir/wc.cpp.s

CMakeFiles/hardware_map.dir/disk/disk.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/disk/disk.cpp.o: ../disk/disk.cpp
CMakeFiles/hardware_map.dir/disk/disk.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/hardware_map.dir/disk/disk.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/disk/disk.cpp.o -MF CMakeFiles/hardware_map.dir/disk/disk.cpp.o.d -o CMakeFiles/hardware_map.dir/disk/disk.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/disk/disk.cpp

CMakeFiles/hardware_map.dir/disk/disk.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/disk/disk.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/disk/disk.cpp > CMakeFiles/hardware_map.dir/disk/disk.cpp.i

CMakeFiles/hardware_map.dir/disk/disk.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/disk/disk.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/disk/disk.cpp -o CMakeFiles/hardware_map.dir/disk/disk.cpp.s

CMakeFiles/hardware_map.dir/battery/battery.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/battery/battery.cpp.o: ../battery/battery.cpp
CMakeFiles/hardware_map.dir/battery/battery.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/hardware_map.dir/battery/battery.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/battery/battery.cpp.o -MF CMakeFiles/hardware_map.dir/battery/battery.cpp.o.d -o CMakeFiles/hardware_map.dir/battery/battery.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/battery/battery.cpp

CMakeFiles/hardware_map.dir/battery/battery.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/battery/battery.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/battery/battery.cpp > CMakeFiles/hardware_map.dir/battery/battery.cpp.i

CMakeFiles/hardware_map.dir/battery/battery.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/battery/battery.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/battery/battery.cpp -o CMakeFiles/hardware_map.dir/battery/battery.cpp.s

CMakeFiles/hardware_map.dir/d.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/d.cpp.o: ../d.cpp
CMakeFiles/hardware_map.dir/d.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/hardware_map.dir/d.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/d.cpp.o -MF CMakeFiles/hardware_map.dir/d.cpp.o.d -o CMakeFiles/hardware_map.dir/d.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/d.cpp

CMakeFiles/hardware_map.dir/d.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/d.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/d.cpp > CMakeFiles/hardware_map.dir/d.cpp.i

CMakeFiles/hardware_map.dir/d.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/d.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/d.cpp -o CMakeFiles/hardware_map.dir/d.cpp.s

CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o: ../wireless/wifi.cpp
CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o -MF CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o.d -o CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/wireless/wifi.cpp

CMakeFiles/hardware_map.dir/wireless/wifi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/wireless/wifi.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/wireless/wifi.cpp > CMakeFiles/hardware_map.dir/wireless/wifi.cpp.i

CMakeFiles/hardware_map.dir/wireless/wifi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/wireless/wifi.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/wireless/wifi.cpp -o CMakeFiles/hardware_map.dir/wireless/wifi.cpp.s

CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o: ../ethernet/ethernet.cpp
CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o -MF CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o.d -o CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/ethernet/ethernet.cpp

CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/ethernet/ethernet.cpp > CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.i

CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/ethernet/ethernet.cpp -o CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.s

CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o: ../bluetooth/bluetooth.cpp
CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o -MF CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o.d -o CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/bluetooth/bluetooth.cpp

CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/bluetooth/bluetooth.cpp > CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.i

CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/bluetooth/bluetooth.cpp -o CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.s

CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o: ../keyboard/keyboard.cpp
CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o -MF CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o.d -o CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/keyboard/keyboard.cpp

CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/keyboard/keyboard.cpp > CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.i

CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/keyboard/keyboard.cpp -o CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.s

CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o: ../mouse/mouse.cpp
CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o -MF CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o.d -o CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/mouse/mouse.cpp

CMakeFiles/hardware_map.dir/mouse/mouse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/mouse/mouse.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/mouse/mouse.cpp > CMakeFiles/hardware_map.dir/mouse/mouse.cpp.i

CMakeFiles/hardware_map.dir/mouse/mouse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/mouse/mouse.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/mouse/mouse.cpp -o CMakeFiles/hardware_map.dir/mouse/mouse.cpp.s

CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o: ../touchpad/touchpad.cpp
CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o -MF CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o.d -o CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/touchpad/touchpad.cpp

CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/touchpad/touchpad.cpp > CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.i

CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/touchpad/touchpad.cpp -o CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.s

CMakeFiles/hardware_map.dir/audio/audio.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/audio/audio.cpp.o: ../audio/audio.cpp
CMakeFiles/hardware_map.dir/audio/audio.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/hardware_map.dir/audio/audio.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/audio/audio.cpp.o -MF CMakeFiles/hardware_map.dir/audio/audio.cpp.o.d -o CMakeFiles/hardware_map.dir/audio/audio.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/audio/audio.cpp

CMakeFiles/hardware_map.dir/audio/audio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/audio/audio.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/audio/audio.cpp > CMakeFiles/hardware_map.dir/audio/audio.cpp.i

CMakeFiles/hardware_map.dir/audio/audio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/audio/audio.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/audio/audio.cpp -o CMakeFiles/hardware_map.dir/audio/audio.cpp.s

CMakeFiles/hardware_map.dir/mic/mic.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/mic/mic.cpp.o: ../mic/mic.cpp
CMakeFiles/hardware_map.dir/mic/mic.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/hardware_map.dir/mic/mic.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/mic/mic.cpp.o -MF CMakeFiles/hardware_map.dir/mic/mic.cpp.o.d -o CMakeFiles/hardware_map.dir/mic/mic.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/mic/mic.cpp

CMakeFiles/hardware_map.dir/mic/mic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/mic/mic.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/mic/mic.cpp > CMakeFiles/hardware_map.dir/mic/mic.cpp.i

CMakeFiles/hardware_map.dir/mic/mic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/mic/mic.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/mic/mic.cpp -o CMakeFiles/hardware_map.dir/mic/mic.cpp.s

CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o: ../gpu/gpu.cpp
CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o -MF CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o.d -o CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/gpu/gpu.cpp

CMakeFiles/hardware_map.dir/gpu/gpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/gpu/gpu.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/gpu/gpu.cpp > CMakeFiles/hardware_map.dir/gpu/gpu.cpp.i

CMakeFiles/hardware_map.dir/gpu/gpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/gpu/gpu.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/gpu/gpu.cpp -o CMakeFiles/hardware_map.dir/gpu/gpu.cpp.s

CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o: CMakeFiles/hardware_map.dir/flags.make
CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o: ../sys_info/sys_info.cpp
CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o: CMakeFiles/hardware_map.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Building CXX object CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o -MF CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o.d -o CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o -c /home/vijay-16033/Documents/Repos_handler/Hardware_Map/sys_info/sys_info.cpp

CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vijay-16033/Documents/Repos_handler/Hardware_Map/sys_info/sys_info.cpp > CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.i

CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vijay-16033/Documents/Repos_handler/Hardware_Map/sys_info/sys_info.cpp -o CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.s

# Object files for target hardware_map
hardware_map_OBJECTS = \
"CMakeFiles/hardware_map.dir/main.cpp.o" \
"CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o" \
"CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o" \
"CMakeFiles/hardware_map.dir/memory/memory.cpp.o" \
"CMakeFiles/hardware_map.dir/ram/ram.cpp.o" \
"CMakeFiles/hardware_map.dir/display/display.cpp.o" \
"CMakeFiles/hardware_map.dir/wc.cpp.o" \
"CMakeFiles/hardware_map.dir/disk/disk.cpp.o" \
"CMakeFiles/hardware_map.dir/battery/battery.cpp.o" \
"CMakeFiles/hardware_map.dir/d.cpp.o" \
"CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o" \
"CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o" \
"CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o" \
"CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o" \
"CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o" \
"CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o" \
"CMakeFiles/hardware_map.dir/audio/audio.cpp.o" \
"CMakeFiles/hardware_map.dir/mic/mic.cpp.o" \
"CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o" \
"CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o"

# External object files for target hardware_map
hardware_map_EXTERNAL_OBJECTS =

hardware_map: CMakeFiles/hardware_map.dir/main.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/cpu/cpu.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/webcam/webcam.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/memory/memory.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/ram/ram.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/display/display.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/wc.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/disk/disk.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/battery/battery.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/d.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/wireless/wifi.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/ethernet/ethernet.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/bluetooth/bluetooth.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/keyboard/keyboard.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/mouse/mouse.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/touchpad/touchpad.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/audio/audio.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/mic/mic.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/gpu/gpu.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/sys_info/sys_info.cpp.o
hardware_map: CMakeFiles/hardware_map.dir/build.make
hardware_map: /usr/lib/x86_64-linux-gnu/libX11.so
hardware_map: /usr/lib/x86_64-linux-gnu/libXext.so
hardware_map: /usr/lib/x86_64-linux-gnu/libXrandr.so
hardware_map: /usr/lib/x86_64-linux-gnu/libX11.so
hardware_map: /usr/lib/x86_64-linux-gnu/libXext.so
hardware_map: /usr/lib/x86_64-linux-gnu/libXrandr.so
hardware_map: /usr/lib/x86_64-linux-gnu/libcurl.so
hardware_map: /usr/lib/x86_64-linux-gnu/libasound.so
hardware_map: CMakeFiles/hardware_map.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_21) "Linking CXX executable hardware_map"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hardware_map.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hardware_map.dir/build: hardware_map
.PHONY : CMakeFiles/hardware_map.dir/build

CMakeFiles/hardware_map.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hardware_map.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hardware_map.dir/clean

CMakeFiles/hardware_map.dir/depend:
	cd /home/vijay-16033/Documents/Repos_handler/Hardware_Map/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vijay-16033/Documents/Repos_handler/Hardware_Map /home/vijay-16033/Documents/Repos_handler/Hardware_Map /home/vijay-16033/Documents/Repos_handler/Hardware_Map/build /home/vijay-16033/Documents/Repos_handler/Hardware_Map/build /home/vijay-16033/Documents/Repos_handler/Hardware_Map/build/CMakeFiles/hardware_map.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hardware_map.dir/depend
