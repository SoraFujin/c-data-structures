#!/bin/bash

project_root="$(cd "$(dirname "$0")/.." && pwd)"
rm -rf "$project_root/bin"
echo "🧹 Cleaned up compiled binaries (bin/ directory removed)."
