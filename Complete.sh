#!/bin/bash

# Complete.sh: Install Mochiarch dotfiles, Elegant-grub2-themes, Momoisay repos, replace Hyprland configs, and manage display managers and notification/lock services

set -e

DOTFILES_DIR="$HOME/dotfiles/configs"
CONFIG_DIR="$HOME/.config"
BACKUP_DIR="$HOME/dotfiles/backup"
USER=$(whoami)
LOG_FILE="$HOME/dotfiles/install.log"

log() {
    echo "[$(date '+%Y-%m-%d %H:%M:%S')] $1" | tee -a "$LOG_FILE"
}

command_exists() {
    command -v "$1" >/dev/null 2>&1
}

log "Creating backup directory at $BACKUP_DIR"
mkdir -p "$BACKUP_DIR"

if [ ! -d "$DOTFILES_DIR" ]; then
    log "Error: $DOTFILES_DIR not found. Please ensure your dotfiles are in ~/dotfiles/configs/"
    exit 1
fi

log "Installing required dependencies..."
if ! command_exists git; then
    sudo pacman -S --noconfirm git
fi
if ! command_exists yay; then
    log "Installing yay AUR helper..."
    git clone https://aur.archlinux.org/yay.git /tmp/yay
    cd /tmp/yay
    makepkg -si --noconfirm
    cd -
fi

log "Disabling and uninstalling SDDM..."
if systemctl is-enabled sddm.service >/dev/null 2>&1; then
    sudo systemctl disable sddm.service
    log "SDDM disabled"
fi
if pacman -Qs sddm >/dev/null; then
    sudo pacman -Rns --noconfirm sddm
    log "SDDM uninstalled"
else
    log "SDDM not installed, skipping uninstallation"
fi

log "Installing and enabling GDM..."
if ! pacman -Qs gdm >/dev/null; then
    sudo pacman -S --noconfirm gdm
    sudo systemctl enable gdm.service
    log "GDM installed and enabled"
else
    log "GDM already installed"
    if ! systemctl is-enabled gdm.service >/dev/null 2>&1; then
        sudo systemctl enable gdm.service
        log "GDM enabled"
    else
        log "GDM already enabled"
    fi
fi

log "Disabling and uninstalling Dunst..."
if systemctl is-enabled --user dunst.service >/dev/null 2>&1; then
    systemctl --user disable dunst.service
    log "Dunst disabled"
fi
if pacman -Qs dunst >/dev/null; then
    sudo pacman -Rns --noconfirm dunst
    log "Dunst uninstalled"
else
    log "Dunst not installed, skipping uninstallation"
fi

log "Installing and enabling Swaync..."
if ! pacman -Qs swaync >/dev/null; then
    sudo pacman -S --noconfirm swaync
    systemctl --user enable swaync.service
    log "Swaync installed and enabled"
else
    log "Swaync already installed"
    if ! systemctl --user is-enabled swaync.service >/dev/null 2>&1; then
        systemctl --user enable swaync.service
        log "Swaync enabled"
    else
        log "Swaync already enabled"
    fi
fi

log "Disabling and uninstalling Swaylock..."
if pacman -Qs swaylock >/dev/null; then
    sudo pacman -Rns --noconfirm swaylock
    log "Swaylock uninstalled"
else
    log "Swaylock not installed, skipping uninstallation"
fi

log "Installing Hyprlock..."
if ! pacman -Qs hyprlock >/dev/null; then
    sudo pacman -S --noconfirm hyprlock
    log "Hyprlock installed"
else
    log "Hyprlock already installed"
fi

log "Installing Elegant-grub2-themes from GitHub..."
if [ ! -d "/tmp/Elegant-grub2-themes" ]; then
    git clone https://github.com/vinceliuice/Elegant-grub2-themes.git /tmp/Elegant-grub2-themes
    cd /tmp/Elegant-grub2-themes
    sudo ./install.sh -t forest -s 1080p
    cd -
else
    log "Elegant-grub2-themes repo already cloned"
fi

log "Installing Momoisay repository from GitHub..."
if [ ! -d "/tmp/Momoisay" ]; then
    git clone https://github.com/Mon4sm/Momoisay.git /tmp/Momoisay
    cd /tmp/Momoisay
    if [ -f "install/linux.sh" ]; then
        log "Running Momoisay install/linux.sh..."
        sudo sh ./install/linux.sh
    else
        log "Error: install/linux.sh not found in Momoisay repo. Skipping."
        cd -
        exit 1
    fi
    cd -
else
    log "Momoisay repo already cloned"
fi

if [ -d "$CONFIG_DIR/hypr" ]; then
    log "Backing up existing Hyprland config to $BACKUP_DIR/hypr-$(date '+%Y%m%d%H%M%S')"
    mv "$CONFIG_DIR/hypr" "$BACKUP_DIR/hypr-$(date '+%Y%m%d%H%M%S')"
fi

log "Symlinking dotfiles from $DOTFILES_DIR to $CONFIG_DIR..."
mkdir -p "$CONFIG_DIR"
for item in "$DOTFILES_DIR"/*; do
    item_name=$(basename "$item")
    target="$CONFIG_DIR/$item_name"
    if [ -e "$target" ]; then
        log "Backing up existing $target to $BACKUP_DIR/$item_name-$(date '+%Y%m%d%H%M%S')"
        mv "$target" "$BACKUP_DIR/$item_name-$(date '+%Y%m%d%H%M%S')"
    fi
    ln -sf "$item" "$target"
    log "Symlinked $item to $target"
done

if [ -d "$DOTFILES_DIR/hypr" ]; then
    log "Replacing Hyprland configs in $CONFIG_DIR/hypr..."
    rm -rf "$CONFIG_DIR/hypr"
    ln -sf "$DOTFILES_DIR/hypr" "$CONFIG_DIR/hypr"
    log "Hyprland configs replaced successfully"
else
    log "Warning: Hyprland configs not found in $DOTFILES_DIR/hypr"
fi

log "Setting permissions for $CONFIG_DIR..."
sudo chmod -R 700 "$CONFIG_DIR"

log "Installing additional dependencies (Hyprland, Waybar, Kitty, Rofi, Fish, Hyprlock)..."
sudo pacman -S --noconfirm hyprland waybar kitty rofi fish hyprlock

log "Installation complete! Rebooting system..."
read -p "Press Enter to reboot now..."
sudo reboot