#!/bin/zsh

# This line compiles your program
gcc main.c -o main -Wall -Wextra

# Check if the compilation was successful
if [[ $? -eq 0 ]]; then
    echo "Compilation successful!"
else
    echo "Compilation failed!"
    exit 1
fi

