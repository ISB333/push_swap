#!/bin/bash

# Array containing different combinations of arguments
ARGS=(
    "1 2 3"
    "1 3 2"
    "2 1 3"
    "2 3 1"
    "3 1 2"
    "3 2 1"
)

# Path to your executable
EXECUTABLE="./your_program"

# Loop through each combination of arguments
for arg in "${ARGS[@]}"
do
    # Execute your program with the current arguments
    $EXECUTABLE "$arg"
done
