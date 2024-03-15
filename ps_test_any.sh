#!/bin/bash

EXECUTABLE="./push_swap"

# Function to generate a series of 5 random integers without duplicates
generate_random_series() {
  series=()
  while (( ${#series[@]} < 500 )); do
    new_num=$((RANDOM % 500 + 1))
    if [[ ! " ${series[@]} " =~ " $new_num " ]]; then
      series+=( "$new_num" )
    fi
  done
  echo "${series[@]}"
}

# Initialize variables for lowest, highest, and total moves
lowest_moves=10000  # Start with a high value
highest_moves=0
total_moves=0

# Execute the executable with different series
for ((i = 1; i <= 100; i++)); do  # Adjust the number of runs as needed
  SERIES=$(generate_random_series)
  echo "Executing run $i with series: $SERIES"
  echo "-------------------------------------"
  moves=$($EXECUTABLE "$SERIES" | wc -l)
  echo "Number of moves: $moves"
  echo "-------------------------------------"
  
  # Update lowest and highest moves
  if ((moves < lowest_moves)); then
    lowest_moves=$moves
  fi
  if ((moves > highest_moves)); then
    highest_moves=$moves
  fi
  
  # Add moves to total
  total_moves=$((total_moves + moves))
done

# Calculate average moves
average_moves=$((total_moves / 100))  # Divide by the number of runs

echo "Lowest number of moves: $lowest_moves"
echo "Highest number of moves: $highest_moves"
echo "Average number of moves: $average_moves"
