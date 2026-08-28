#!/bin/bash
# Exit immediately if a command exits with a non-zero status
set -e

# Create bin directory if it doesn't exist
mkdir -p bin

echo "Compiling Pathfinder.dll for Windows (64-bit)..."

# Cross-compile using MinGW
x86_64-w64-mingw32-g++ -shared -o bin/Pathfinder.dll \
    src/Pathfinder.cpp \
    src/UnityBridge.cpp \
    -O3 -std=c++17 -static-libgcc -static-libstdc++ -Wl,--no-undefined

echo "Build complete! Output: bin/Pathfinder.dll"