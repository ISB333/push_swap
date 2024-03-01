#!/bin/bash

EXECUTABLE="./push_swap"

# Function to generate a series of 5 random integers without duplicates
generate_random_series() {
  series=()
  while (( ${#series[@]} < 30 )); do
    new_num=$((RANDOM % 30 + 1))
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
