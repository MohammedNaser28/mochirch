#!/bin/bash
# ✨ Hyprland Quick Cheat Sheet – Full Keybindings ✨

BACKEND=wayland

pkill -f rofi
pkill -f yad

GDK_BACKEND=$BACKEND yad \
  --center \
  --title="🎹 Hyprland Cheat Sheet" \
  --no-buttons \
  --width=950 \
  --height=750 \
  --list \
  --separator="" \
  --column="🔑 Keybind:TEXT" \
  --column="📝 Description:TEXT" \
  --column="🚀 Command:TEXT" \
  --align="center" \
  --fontname="monospace 10" \
\
"Super + Return"       "Terminal"                         "\$term" \
"Super + E"            "File Manager"                     "\$files" \
"Ctrl + Shift + Esc"   "System Monitor (btop)"            "\$term -e btop" \
"Super + W"            "Select Wallpaper"                 "WallpaperSelect.sh" \
"Shift + Super + W"    "Wallpaper Effects"                "WallpaperEffects.sh" \
"Ctrl + Alt + W"       "Random Wallpaper"                 "WallpaperRandom.sh" \
"Super + O"            "Change Zsh Theme"                 "ZshChangeTheme.sh" \
"Super + H"            "Help / Cheat Sheet"               "KeyHints.sh" \
"Shift + Super + K"    "Search Keybinds (Rofi)"           "KeyBinds.sh" \
"Shift + Super + A"    "Animations Menu"                  "Animations.sh" \
"Super + Print"        "Screenshot Now"                   "ScreenShot.sh --now" \
"Shift + Super + Print"  "Screenshot Area"                  "ScreenShot.sh --area" \
"Alt + Print"          "Screenshot Active Window"         "ScreenShot.sh --active" \
"Super + P"            "Audio Settings"                   "pavucontrol" \
"Super + V"            "Clipboard Manager"                "ClipManager.sh" \
"Shift + Super + N"    "Notification Panel (SwayNC)"      "swaync-client -t -sw" \
"Super + D"            "App Launcher (Rofi)"              "rofi -show drun" \
"Super + \`"           "Emoji Menu"                        "RofiEmoji.sh" \
"Super + C"            "Color Picker"                     "color-picker.sh" \
"Super + Alt + C"      "Calculator (Qalculate)"           "RofiCalc.sh" \
"Super + B"            "Toggle Waybar"                    "toggle-bar.sh" \
"Shift + Super + M"    "Rofi Beats (Online Music)"        "RofiBeats.sh" \
"Ctrl + Shift + R"     "Rofi Theme Selector"              "RofiThemeSelector-modified.sh" \
"Super + Alt + R"      "Refresh UI (Rofi/Waybar/SwayNC)"  "Refresh.sh" \
"Ctrl + Alt + P"       "Power Menu"                       "powermenu.sh" \
"Ctrl + Alt + L"       "Lock Screen"                      "LockScreen.sh" \
"Ctrl + Alt + N"       "Network (nmtui)"                  "WaybarScripts.sh --nmtui" \
"Shift + Super + C"    "Visual Studio Code"               "code" \
"Shift + Super + F"    "Firefox Browser"                  "\$browser" \
"Shift + Super + T"    "Telegram"                         "telegram-desktop" \
"Shift + Super + R"    "OBS Studio"                       "obs" \
"Shift + Super + O"    "Obsidian Notes"                   "obsidian" \
"Shift + Super + D"    "Discord"                          "discord" \
"Shift + Super + S"    "Spotify"                          "spotify" \
"Shift + Super + H"    "Heroic Games Launcher"            "heroic" \
"Shift + Super + Y"    "Steam"                            "steam" \
"Audio + (F-key)"      "Raise Volume"                     "volume.sh --device output --action increase" \
"Audio - (F-key)"      "Lower Volume"                     "volume.sh --device output --action decrease" \
"Audio Mute"           "Mute Output"                      "volume.sh --device output --action toggle" \
"Mic Mute"             "Mute Microphone"                  "volume.sh --device input --action toggle" \
"Play/Pause"           "Media Toggle"                     "playerctl play-pause" \
"Next Track"           "Next Media"                       "playerctl next" \
"Previous Track"       "Previous Media"                   "playerctl previous" \
"Stop"                 "Stop Media"                       "playerctl stop" \
"Brightness +"         "Increase Brightness"              "brightness.sh --up" \
"Brightness -"         "Decrease Brightness"              "brightness.sh --down" \
"Alt + Shift"          "Switch Keyboard Layout"           "SwitchKeyboardLayout.sh" \
"Super + Q"            "Close Window"                     "hyprctl dispatch killactive" \
"Super + Space"        "Toggle Floating"                  "togglefloating" \
"Alt + Return"         "Fullscreen Window"                "fullscreen" \
"Ctrl + Shift + F"     "Fake Fullscreen"                  "fullscreen 1" \
"Super + Alt + Space"  "All Float Mode"                   "workspaceopt allfloat" \
"Super + Shift + Enter"  "Dropdown Terminal"                "[float; move 15% 5%; size 70% 60%] \$term" \
"Super + Ctrl + O"     "Toggle Window Opacity"            "setprop active opaque toggle" \
"Super + Alt + O"      "Toggle Blur"                      "ChangeBlur.sh" \
"Super + Alt + L"      "Change Layout Mode"               "ChangeLayout.sh" \
"Super + Shift + G"    "Toggle Game Mode (Animations)"    "GameMode.sh" \
"Super + Alt + Mouse↓" "Cursor Zoom In"                   "zoom_factor * 2.0" \
"Super + Alt + Mouse↑" "Cursor Zoom Out"                  "zoom_factor / 2.0" \
"Ctrl + Alt + Delete"  "Exit Hyprland"                    "hyprctl dispatch exit 0" \
"Ctrl + Shift + R"     "Reload Hyprland Config"           "hyprctl reload" \
"Shift + Super + Q"    "Kill Active Process"              "KillActiveProcess.sh" \
"ESC"                  "Close this window"                "❌"
