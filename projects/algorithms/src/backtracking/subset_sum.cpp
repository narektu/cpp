#include "../../include/backtracking/subset_sum.h"
#include <iostream>
#include <vector>

void subsetSum(std::vector<int>& set, std::vector<int>& subset, int n, int subSize, int total, int nodeCount, int sum) {
    if (total == sum) {
        for (int i = 0; i < subSize; i++) std::cout << subset[i] << " ";
        std::cout << std::endl;
        subsetSum(set, subset, n, subSize - 1, total - set[nodeCount], nodeCount + 1, sum);
        return;
    } else {
        for (int i = nodeCount; i < n; i++) {
            subset[subSize] = set[i];
            subsetSum(set, subset, n, subSize + 1, total + set[i], i + 1, sum);
        }
    }
}

void run_subset_sum() {
    std::cout << "Running Algorithm: Subset Sum" << std::endl;
    std::vector<int> set = {10, 7, 5, 18, 12, 20, 15};
    int sum = 35;
    std::vector<int> subset(set.size());
    subsetSum(set, subset, set.size(), 0, 0, 0, sum);
}
