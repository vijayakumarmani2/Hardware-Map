#!/bin/bash

# Exit on error
set -e

# Ensure the script is run as root
if [ "$(id -u)" != "0" ]; then
   echo "This script must be run as root" 1>&2
   exit 1
fi

# Define installation directories
INSTALL_DIR="/usr/local"
BIN_DIR="$INSTALL_DIR/bin"
SHARE_DIR="$INSTALL_DIR/share"
GUI_DIR="$SHARE_DIR/hardware_map_gui"

#install cmake make
sudo apt-get install cmake make

#install neccessory packages...
sudo apt-get install libx11-dev libxrandr-dev libcurl4-openssl-dev libudev-dev libasound2-dev libbluetooth-dev pkg-config
 
# Step 1: Compile and install the command-line tool
echo "Compiling the command-line tool..."
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local
make
make install
cd ..
sudo chmod 777 /usr/local/bin/hardware_map

# Step 2: Install the PyQt GUI application
echo "Installing the GUI application..."
mkdir -p "$GUI_DIR"
cp -r hardware_map_gui/* "$GUI_DIR"

# Create a virtual environment for the application's Python dependencies
VENV_DIR="$GUI_DIR/venv"
python3 -m venv "$VENV_DIR"
source "$VENV_DIR/bin/activate"

# Install Python dependencies
pip install ezodf==0.3.2 openpyxl==3.1.2 PyQt5==5.15.10 PyQt5_sip==12.13.0 python_docx==1.0.1

# Deactivate the virtual environment
deactivate

# Create a wrapper script to run the GUI with the virtual environment
WRAPPER_SCRIPT="$BIN_DIR/hardware_map_gui"
cat > "$WRAPPER_SCRIPT" <<EOF
#!/bin/bash
source "$VENV_DIR/bin/activate"
python "$GUI_DIR/hardware_map_gui.py" "\$@"
deactivate
EOF
chmod +x "$WRAPPER_SCRIPT"

# Step 3: Handle desktop integration
echo "Creating desktop entry for the GUI application..."
DESKTOP_ENTRY="/usr/share/applications/hardware_map_gui.desktop"
cat > "$DESKTOP_ENTRY" <<EOF
[Desktop Entry]
Version=1.0
Type=Application
Name=Hardware Map Tool
Exec=$WRAPPER_SCRIPT
Icon=hardware_map_gui
Comment=Hardware-map command-line tool with a GUI
Categories=Utility;
Terminal=false
EOF

# Copy your application icon to the appropriate location
cp hw_icon.png /usr/share/icons/hardware_map_gui.png

echo "Installation completed successfully."
