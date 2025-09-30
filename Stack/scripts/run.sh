#!/bin/bash

project_root="$(cd "$(dirname "$0")/.." && pwd)"

if [ ! -f "$project_root/bin/main" ]; then
    echo "❌ Executable not found. Please compile first using ./compile.sh"
    exit 1
fi

"$project_root/bin/main"
