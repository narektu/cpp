#include "../../include/backtracking/n_queens_opt.h"
#include <iostream>

int count = 0;
void solveNQueensOpt(int n, int row, int col, int diag1, int diag2) {
    if (row == n) {
        ::count++;
        return;
    }
    int available = ((1 << n) - 1) & ~(col | diag1 | diag2);
    while (available) {
        int pos = available & -available;
        available ^= pos;
        solveNQueensOpt(n, row + 1, col | pos, (diag1 | pos) << 1, (diag2 | pos) >> 1);
    }
}

void run_n_queens_opt() {
    std::cout << "Running Algorithm: N-Queens (Optimized Bitmasking)" << std::endl;
    ::count = 0;
    int n = 8;
    solveNQueensOpt(n, 0, 0, 0, 0);
    std::cout << "Total solutions for " << n << "-Queens: " << ::count << std::endl;
}
