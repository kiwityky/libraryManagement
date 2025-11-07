#!/bin/bash

# Build and run script for C project
echo "🔨 Building project..."

# Remove old executable if it exists
if [ -f "library_manager" ]; then
    echo "🗑️  Removing old executable..."
    rm -f library_manager
fi

# Build using Makefile
make

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "✅ Build successful!"
    echo "🚀 Running program..."
    echo "===================="
    
    # Run the program
    ./library_manager
else
    echo "❌ Build failed!"
    exit 1
fi