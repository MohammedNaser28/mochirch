#!/bin/bash

# المسار الرئيسي
BASE="/home/mochi-002/Documents/DB - Programmong"

# الفولدرات المطلوبة
DIRS=("competitive" "web/front-end" "web/back-end" "java-oop" "ai-python" "python-scripts")

echo "📁 Creating base folder at \"$BASE\"..."
mkdir -p "$BASE"

# إعداد README حسب نوع المشروع
generate_readme() {
  cat > "$1/README.md" << EOF
# ${1##*/}

This folder contains source code related to **${1##*/}**.

> Automatically generated on $(date '+%Y-%m-%d %H:%M:%S')
EOF
}

# إعداد Git
initialize_git() {
  cd "$1"
  git init -q
  echo -e ".vscode/\na.out\n*.class\n__pycache__/" > .gitignore
  git add .
  git commit -qm "Initial commit for ${1##*/} setup"
}

# إعدادات VSCode مشتركة
add_common_settings() {
  mkdir -p "$1/.vscode"
  cat > "$1/.vscode/settings.json" << EOF
{
  "editor.tabSize": 2,
  "editor.rulers": [80],
  "editor.formatOnSave": true,
  "files.autoSave": "afterDelay"
}
EOF
}

# إعدادات خاصة بكل مجال
setup_vscode_cpp() {
  add_common_settings "$1"
  cat > "$1/.vscode/tasks.json" << EOF
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "build",
      "type": "shell",
      "command": "g++",
      "args": ["-g", "\${file}", "-o", "a.out"],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "problemMatcher": ["\$gcc"]
    }
  ]
}
EOF

  cat > "$1/.vscode/launch.json" << EOF
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Run C++",
      "type": "cppdbg",
      "request": "launch",
      "program": "\${workspaceFolder}/a.out",
      "args": [],
      "stopAtEntry": false,
      "cwd": "\${workspaceFolder}",
      "environment": [],
      "externalConsole": false,
      "MIMode": "gdb",
      "setupCommands": [
        {
          "description": "Enable pretty-printing for gdb",
          "text": "-enable-pretty-printing",
          "ignoreFailures": true
        }
      ],
      "preLaunchTask": "build"
    }
  ]
}
EOF
}

setup_vscode_java() {
  add_common_settings "$1"
  cat > "$1/.vscode/launch.json" << EOF
{
  "version": "0.2.0",
  "configurations": [
    {
      "type": "java",
      "name": "Launch Java",
      "request": "launch",
      "mainClass": "\${file}"
    }
  ]
}
EOF
}

setup_vscode_python() {
  add_common_settings "$1"
  cat > "$1/.vscode/launch.json" << EOF
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Run Python",
      "type": "python",
      "request": "launch",
      "program": "\${file}",
      "console": "integratedTerminal"
    }
  ]
}
EOF
}

# إنشاء الفولدرات والإعدادات
for d in "${DIRS[@]}"; do
  TARGET="$BASE/$d"
  mkdir -p "$TARGET"
  echo "✅ Created: $TARGET"

  # إعداد ملفات VSCode حسب النوع
  if [[ "$d" == "competitive" ]]; then
    setup_vscode_cpp "$TARGET"
  elif [[ "$d" == "java-oop" ]]; then
    setup_vscode_java "$TARGET"
  elif [[ "$d" == "ai-python" || "$d" == "python-scripts" ]]; then
    setup_vscode_python "$TARGET"
  else
    add_common_settings "$TARGET"
  fi

  # إعداد README و Git
  generate_readme "$TARGET"
  initialize_git "$TARGET"
done

echo "🎉 All folders, VSCode configs, README, and Git repos are ready!"
