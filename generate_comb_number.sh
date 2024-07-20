#!/bin/bash

# Create an empty file to store the combinations
output_file="combinations.txt"
> $output_file

# Define the set of numbers
numbers=(0 1 2 3 4 5 6)

# Function to check for duplicates in an array
has_duplicates() {
  local arr=("$@")
  local seen=()
  for num in "${arr[@]}"; do
    if [[ " ${seen[@]} " =~ " $num " ]]; then
      return 0  # Has duplicates
    else
      seen+=("$num")
    fi
  done
  return 1  # No duplicates
}

# Recursive function to generate combinations
generate_combinations() {
  local n=$1
  local prefix=("${@:2}")

  if [ ${#prefix[@]} -eq $n ]; then
    if ! has_duplicates "${prefix[@]}"; then
      echo "${prefix[@]}" >> $output_file
    fi
    return
  fi

  for num in "${numbers[@]}"; do
    generate_combinations $n "${prefix[@]}" $num
  done
}

# Specify the number of elements
num_elements=7

# Generate combinations
generate_combinations $num_elements
