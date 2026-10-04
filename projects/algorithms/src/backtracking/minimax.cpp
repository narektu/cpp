#include "../../include/backtracking/minimax.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int minimax(int depth, int nodeIndex, bool isMax, std::vector<int>& scores, int h) {
    if (depth == h) return scores[nodeIndex];
    if (isMax) {
        return std::max(minimax(depth + 1, nodeIndex * 2, false, scores, h),
                        minimax(depth + 1, nodeIndex * 2 + 1, false, scores, h));
    } else {
        return std::min(minimax(depth + 1, nodeIndex * 2, true, scores, h),
                        minimax(depth + 1, nodeIndex * 2 + 1, true, scores, h));
    }
}

void run_minimax() {
    std::cout << "Running Algorithm: Minimax" << std::endl;
    std::vector<int> scores = {3, 5, 2, 9, 12, 5, 23, 23};
    int h = log2(scores.size());
    int res = minimax(0, 0, true, scores, h);
    std::cout << "Optimal value is: " << res << std::endl;
}
