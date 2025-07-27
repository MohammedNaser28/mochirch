#!/bin/bash

# Complete.sh: Install Mochiarch dotfiles, Elegant-grub2-themes, Momoisay repos, and replace Hyprland configs

# Exit on error
set -e

# Define variables
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

log "Installing Elegant-grub2-themes..."
if ! yay -Qs elegant-grub2-themes >/dev/null; then
    yay -S --noconfirm elegant-grub2-themes
else
    log "Elegant-grub2-themes already installed"
fi

log "Installing Momoisay repository..."
if [ ! -d "/tmp/momoisay" ]; then
    git clone https://github.com/mochi-002/momoisay.git /tmp/momoisay
    cd /tmp/momoisay
    if [ -f "install.sh" ]; then
        log "Running Momoisay install.sh..."
        sh install.sh
    else
        log "Warning: No install.sh found in Momoisay repo. Skipping."
    fi
    cd -
else
    log "Momoisay repo already cloned"
fi

# Backup existing .config/hypr
if [ -d "$CONFIG_DIR/hypr" ]; then
    log "Backing up existing Hyprland config to $BACKUP_DIR/hypr-$(date '+%Y%m%d%H%M%S')"
    mv "$CONFIG_DIR/hypr" "$BACKUP_DIR/hypr-$(date '+%Y%m%d%H%M%S')"
fi

# Symlink dotfiles from ~/dotfiles/configs/ to ~/.config/
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

# Ensure Hyprland configs are replaced
if [ -d "$DOTFILES_DIR/hypr" ]; then
    log "Replacing Hyprland configs in $CONFIG_DIR/hypr..."
    rm -rf "$CONFIG_DIR/hypr"
    ln -sf "$DOTFILES_DIR/hypr" "$CONFIG_DIR/hypr"
    log "Hyprland configs replaced successfully"
else
    log "Warning: Hyprland configs not found in $DOTFILES_DIR/hypr"
fi

# Set permissions
log "Setting permissions for $CONFIG_DIR..."
sudo chmod -R 700 "$CONFIG_DIR"

# Install additional dependencies (based on your README)
log "Installing additional dependencies (Hyprland, Waybar, Kitty, Rofi, Swaync, Fish)..."
sudo pacman -S --noconfirm hyprland waybar kitty rofi swaync fish

# Reboot
log "Installation complete! Rebooting system..."
read -p "Press Enter to reboot now..."
sudo reboot