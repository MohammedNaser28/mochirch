#!/bin/bash

# Ensure script runs from dotfiles directory
DOTFILES_DIR="$HOME/dotfiles"
cd "$DOTFILES_DIR" || { echo "Error: Cannot change to $DOTFILES_DIR"; exit 1; }

# Set console font
if ! setfont cyr-sun16 2>/dev/null; then
    echo "Warning: Font cyr-sun16 not found. Ensure kbd package is installed."
fi

clear

echo """
   o o o 
   | | | 
   ~ ~ ~ 

███╗   ███╗ ██████╗  ██████╗██╗  ██╗██╗
████╗ ████║██╔═══██╗██╔════╝██║  ██║██║
██╔████╔██║██║   ██║██║     ███████║██║
██║╚██╔╝██║██║   ██║██║     ██╔══██║██║
██║ ╚═╝ ██║╚██████╔╝╚██████╗██║  ██║██║
╚═╝     ╚═╝ ╚═════╝  ╚═════╝╚═╝  ╚═╝╚═╝
"""

echo
echo "Starting pre-install..." && sleep 2

##==> Installing basic dependencies for pacman
#######################################################
dependencies=(python python-pip)

for package in "${dependencies[@]}"; do
    if ! pacman -Q "$package" &>/dev/null; then
        echo "Installing $package..."
        sudo pacman -S --needed "$package" --noconfirm
    else
        echo "$package is already installed."
    fi
done

#######################################################
##==> Installing python and dependencies for it
#######################################################
declare -a packages=(
    "inquirer"
    "loguru"
    "psutil"
    "gputil"
    "pyamdgpuinfo"
    "pyyaml"
    "pillow"
    "colorama"
)

for package in "${packages[@]}"; do
    if ! pip show "$package" &>/dev/null; then
        echo "Installing Python package $package..."
        pip install "$package" --break-system-packages
    else
        echo "Python package $package is already installed."
    fi
done

#######################################################
##==> Building the system
#######################################################
if [ -f "$DOTFILES_DIR/Builder/install.py" ]; then
    echo "Running Builder/install.py..."
    python "$DOTFILES_DIR/Builder/install.py"
else
    echo "Error: $DOTFILES_DIR/Builder/install.py not found"
    exit 1
fi
