#include "../../include/backtracking/sudoku_solver.h"
#include <iostream>
#include <vector>

const int N = 9;

bool isSafeSudoku(std::vector<std::vector<int>>& grid, int row, int col, int num) {
    for (int x = 0; x < N; ++x) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudokuUtil(std::vector<std::vector<int>>& grid) {
    int row = -1;
    int col = -1;
    bool isEmpty = false;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = true;
                break;
            }
        }
        if (isEmpty) break;
    }
    if (!isEmpty) return true;

    for (int num = 1; num <= 9; ++num) {
        if (isSafeSudoku(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudokuUtil(grid)) return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void run_sudoku_solver() {
    std::cout << "Running Algorithm: Sudoku Solver" << std::endl;
    std::vector<std::vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    if (solveSudokuUtil(grid)) {
        std::cout << "Sudoku solved:" << std::endl;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                std::cout << grid[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution exists." << std::endl;
    }
}
