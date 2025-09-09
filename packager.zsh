#!/bin/zsh

# Get the directory where this script is located
SCRIPT_DIR="${0:A:h}"

# Check if any arguments were provided
if [ $# -lt 2 ]; then
    echo "Usage: $0 <target_directory> <folder1> [folder2] [folder3] ..."
    echo "Copies specified folders to <target_directory> in the script's directory"
    exit 1
fi

# Get the target directory name from the first argument
TARGET_DIR_NAME="$1"
shift  # Remove the first argument so $@ now contains only folder names

# Create the target folder in the script's directory if it doesn't exist
TARGET_DIR="$SCRIPT_DIR/$TARGET_DIR_NAME"
mkdir -p "$TARGET_DIR"

# Clear the target directory if it already contains files
if [ "$(ls -A "$TARGET_DIR" 2>/dev/null)" ]; then
    echo "Clearing existing contents in $TARGET_DIR..."
    rm -rf "$TARGET_DIR"/*
fi

# Process each folder argument
for folder in "$@"; do
    if [ -d "$folder" ]; then
        echo "Copying $folder to $TARGET_DIR..."
        cp -r "$folder" "$TARGET_DIR/"
        if [ $? -eq 0 ]; then
            echo "✓ Successfully copied $folder"
        else
            echo "✗ Failed to copy $folder"
        fi
    else
        echo "⚠ Warning: $folder is not a directory or doesn't exist - skipping"
    fi
done

echo "Done! All folders copied to $TARGET_DIR"
