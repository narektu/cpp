#!/bin/bash

# Base paths
INCLUDE_DIR="projects/algorithms/include/backtracking"
SRC_DIR="projects/algorithms/src/backtracking"

mkdir -p "$INCLUDE_DIR"
mkdir -p "$SRC_DIR"

files=(
    "generate_parentheses"
    "graph_coloring"
    "knight_tour"
    "magic_sequence"
    "minimax"
    "n_queens"
    "n_queens_opt"
    "rat_maze"
    "subarray_sum"
    "subset_sum"
    "sudoku_solver"
    "wildcard_matching"
)

for file in "${files[@]}"; do
    # 1. Create header (.h)
    header_file="$INCLUDE_DIR/$file.h"
    if [ ! -f "$header_file" ]; then
        echo "#pragma once" > "$header_file"
        echo "" >> "$header_file"
        echo "// Function to run the example for $file" >> "$header_file"
        echo "void run_$file();" >> "$header_file"
        echo "Created $header_file"
    fi

    # 2. Create implementation (.cpp)
    src_file="$SRC_DIR/$file.cpp"
    if [ ! -f "$src_file" ]; then
        echo "#include \"../../include/backtracking/$file.h\"" > "$src_file"
        echo "#include <iostream>" >> "$src_file"
        echo "" >> "$src_file"
        echo "void run_$file() {" >> "$src_file"
        echo "    std::cout << \"Running Algorithm: $file\" << std::endl;" >> "$src_file"
        echo "    // TODO: Implement logic here" >> "$src_file"
        echo "}" >> "$src_file"
        echo "Created $src_file"
    fi
done

echo "Done!"