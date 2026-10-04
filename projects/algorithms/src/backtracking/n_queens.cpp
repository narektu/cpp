#include "../../include/backtracking/n_queens.h"
#include <iostream>
#include <vector>

bool isSafe(const std::vector<std::string>& board, int row, int col, int n) {
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void solveNQueensUtil(std::vector<std::string>& board, int row, int n, std::vector<std::vector<std::string>>& solutions) {
    if (row == n) {
        solutions.push_back(board);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(board, row, col, n)) {
            board[row][col] = 'Q';
            solveNQueensUtil(board, row + 1, n, solutions);
            board[row][col] = '.';
        }
    }
}

void run_n_queens() {
    std::cout << "Running Algorithm: N-Queens" << std::endl;
    int n = 4;
    std::vector<std::string> board(n, std::string(n, '.'));
    std::vector<std::vector<std::string>> solutions;
    
    solveNQueensUtil(board, 0, n, solutions);
    
    std::cout << "Found " << solutions.size() << " solutions for " << n << "-Queens:" << std::endl;
    for (const auto& sol : solutions) {
        for (const auto& row : sol) {
            std::cout << row << std::endl;
        }
        std::cout << "---" << std::endl;
    }
}
