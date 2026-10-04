#include "../../include/backtracking/knight_tour.h"
#include <iostream>
#include <vector>
#include <iomanip>

#define N 8
int cx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int cy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

bool isSafe(int x, int y, const std::vector<std::vector<int>>& sol) {
    return (x >= 0 && x < N && y >= 0 && y < N && sol[x][y] == -1);
}

bool solveKTUtil(int x, int y, int movei, std::vector<std::vector<int>>& sol) {
    if (movei == N * N) return true;
    for (int k = 0; k < 8; k++) {
        int next_x = x + cx[k];
        int next_y = y + cy[k];
        if (isSafe(next_x, next_y, sol)) {
            sol[next_x][next_y] = movei;
            if (solveKTUtil(next_x, next_y, movei + 1, sol)) return true;
            sol[next_x][next_y] = -1;
        }
    }
    return false;
}

void run_knight_tour() {
    std::cout << "Running Algorithm: Knight Tour" << std::endl;
    std::vector<std::vector<int>> sol(N, std::vector<int>(N, -1));
    sol[0][0] = 0;
    if (solveKTUtil(0, 0, 1, sol)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) std::cout << std::setw(2) << sol[i][j] << " ";
            std::cout << std::endl;
        }
    } else {
        std::cout << "No solution exists" << std::endl;
    }
}
