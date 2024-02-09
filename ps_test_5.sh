#!/bin/bash

EXECUTABLE="./push_swap"

# Define 15 sets of 5 random numbers
sets=(
    "1 2 3 4 5"
    "5 4 3 2 1"
    "2 1 5 4 3"
    "3 4 1 2 5"
    # Add more sets here as needed
)

# Execute the program with each set of numbers
for set in "${sets[@]}"; do
    echo "Testing with input: $set"
    $EXECUTABLE "$set"
    echo "------------------------------------"
done
