#!/bin/bash

# Check if an argument is provided
if [ $# -ne 1 ]; then
    echo "Usage: $0 <number>"
    exit 1
fi

# Extract the number from the argument
number=$1

# Define the executable
EXECUTABLE="./push_swap"

# Function to generate a series of random integers without duplicates
generate_random_series() {
  series=()
  while (( ${#series[@]} < number )); do
    new_num=$((RANDOM % 100000 + 1))
    if [[ ! " ${series[@]} " =~ " $new_num " ]]; then
      series+=( "$new_num" )
    fi
  done
  echo "${series[@]}"
}

# Execute the executable with different series
for ((i = 1; i <= 1; i++)); do
  SERIES=$(generate_random_series)
  echo "Executing run $i with series: $SERIES"
  echo "-------------------------------------"
  $EXECUTABLE "$SERIES" | tee >(wc -l)
  echo "-------------------------------------"
done
