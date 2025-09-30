#!/bin/bash

project_root="$(cd "$(dirname "$0")/.." && pwd)"
mkdir -p "$project_root/bin"

gcc "$project_root/src/main.c" -o "$project_root/bin/main" -Wall -Wextra -I"$project_root/include"

if [ $? -eq 0 ]; then
    echo "✅ Compilation completed. Executable is in bin/main"
else
    echo "❌ Compilation failed."
fi
