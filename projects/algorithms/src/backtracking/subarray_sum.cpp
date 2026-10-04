#include "../../include/backtracking/subarray_sum.h"
#include <iostream>
#include <vector>

void run_subarray_sum() {
    std::cout << "Running Algorithm: Subarray Sum" << std::endl;
    std::vector<int> arr = {1, 4, 20, 3, 10, 5};
    int sum = 33;
    int curr_sum = arr[0], start = 0, i;
    for (i = 1; i <= arr.size(); i++) {
        while (curr_sum > sum && start < i - 1) {
            curr_sum = curr_sum - arr[start];
            start++;
        }
        if (curr_sum == sum) {
            std::cout << "Sum found between indexes " << start << " and " << i - 1 << std::endl;
            return;
        }
        if (i < arr.size()) curr_sum = curr_sum + arr[i];
    }
    std::cout << "No subarray found" << std::endl;
}
