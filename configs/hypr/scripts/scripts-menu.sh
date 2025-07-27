#!/bin/bash
# ---- ⚡ Rofi Script Launcher ---- #

# Directories
scripts_dir="$HOME/.config/hypr/scripts"
userScripts_dir="$HOME/.config/hypr/UserScripts"
rofi_theme="$HOME/.config/rofi/config-scripts.rasi"
msg='🛠️ Select a script to execute'

# Collect all executable .sh scripts from both directories
scripts=$(find "$scripts_dir" "$userScripts_dir" -type f -name "*.sh" -executable)

# Exit if no scripts are found
if [[ -z "$scripts" ]]; then
    notify-send "🚫 No executable scripts found"
    exit 1
fi

# Show script names in rofi (just basenames)
selected=$(echo "$scripts" | xargs -n1 basename | sort -u | rofi -dmenu -i -config "$rofi_theme" -mesg "$msg" -p "🔧 Script")

# Exit if nothing was selected
[[ -z "$selected" ]] && exit

# Find full path of selected script
full_path=$(echo "$scripts" | grep "/$selected$")

# If multiple scripts with same name exist, show warning
if [[ $(echo "$full_path" | wc -l) -gt 1 ]]; then
    notify-send "⚠️ Multiple scripts named '$selected' found."
    exit 1
fi

# Run the selected script
bash "$full_path"
