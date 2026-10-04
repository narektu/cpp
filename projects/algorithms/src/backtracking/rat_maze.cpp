#include "../../include/backtracking/rat_maze.h"
#include <iostream>
#include <vector>

bool isSafeRat(const std::vector<std::vector<int>>& maze, int x, int y, int n) {
    return (x >= 0 && x < n && y >= 0 && y < n && maze[x][y] == 1);
}

bool solveMazeUtil(const std::vector<std::vector<int>>& maze, int x, int y, std::vector<std::vector<int>>& sol, int n) {
    if (x == n - 1 && y == n - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }
    if (isSafeRat(maze, x, y, n)) {
        if (sol[x][y] == 1) return false;
        sol[x][y] = 1;
        if (solveMazeUtil(maze, x + 1, y, sol, n)) return true;
        if (solveMazeUtil(maze, x, y + 1, sol, n)) return true;
        if (solveMazeUtil(maze, x - 1, y, sol, n)) return true;
        if (solveMazeUtil(maze, x, y - 1, sol, n)) return true;
        sol[x][y] = 0;
        return false;
    }
    return false;
}

void run_rat_maze() {
    std::cout << "Running Algorithm: Rat in a Maze" << std::endl;
    int n = 4;
    std::vector<std::vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    std::vector<std::vector<int>> sol(n, std::vector<int>(n, 0));

    if (solveMazeUtil(maze, 0, 0, sol, n)) {
        std::cout << "Path found:" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << sol[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No path exists." << std::endl;
    }
}
