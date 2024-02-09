#!/bin/bash

EXECUTABLE="./push_swap"

# Function to generate a series of 5 random integers without duplicates
generate_random_series() {
  series=()
  while (( ${#series[@]} < 10 )); do
    new_num=$((RANDOM % 10 + 1))
    if [[ ! " ${series[@]} " =~ " $new_num " ]]; then
      series+=( "$new_num" )
    fi
  done
  echo "${series[@]}"
}

# Execute the executable with different series
for ((i = 1; i <= 3; i++)); do
  SERIES=$(generate_random_series)
  echo "Executing run $i with series: $SERIES"
  $EXECUTABLE "$SERIES" | tee >(wc -l)
  echo "-------------------------------------"
done
