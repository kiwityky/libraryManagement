#!/bin/bash

# Script to build and run C program in a new terminal window

# Build the project first
echo "🔨 Building project..."

# Remove old executable if it exists
if [ -f "library_manager" ]; then
    echo "🗑️  Removing old executable..."
    rm -f library_manager
fi

# Build using Makefile
make

if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
    
    # Try different terminal emulators
    if command -v gnome-terminal &> /dev/null; then
        gnome-terminal -- bash -c "cd '$PWD' && echo '🚀 Running library_manager...' && ./library_manager; echo; echo 'Press Enter to close...'; read"
    elif command -v xfce4-terminal &> /dev/null; then
        xfce4-terminal --working-directory="$PWD" -e "bash -c 'echo \"🚀 Running library_manager...\" && ./library_manager; echo; echo \"Press Enter to close...\"; read'"
    elif command -v konsole &> /dev/null; then
        konsole --workdir "$PWD" -e bash -c "echo '🚀 Running library_manager...' && ./library_manager; echo; echo 'Press Enter to close...'; read"
    elif command -v xterm &> /dev/null; then
        xterm -e "cd '$PWD' && echo '🚀 Running library_manager...' && ./library_manager; echo; echo 'Press Enter to close...'; read"
    else
        echo "No suitable terminal emulator found. Running in current terminal:"
        ./library_manager
    fi
else
    echo "❌ Build failed!"
    exit 1
fi