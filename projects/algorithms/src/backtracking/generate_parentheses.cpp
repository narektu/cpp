#include "../../include/backtracking/generate_parentheses.h"
#include <iostream>
#include <vector>
#include <string>

void generateParenthesisUtil(int n, int open, int close, std::string s, std::vector<std::string>& ans) {
    if (s.length() == 2 * n) {
        ans.push_back(s);
        return;
    }
    if (open < n) generateParenthesisUtil(n, open + 1, close, s + "(", ans);
    if (close < open) generateParenthesisUtil(n, open, close + 1, s + ")", ans);
}

void run_generate_parentheses() {
    std::cout << "Running Algorithm: Generate Parentheses" << std::endl;
    int n = 3;
    std::vector<std::string> ans;
    generateParenthesisUtil(n, 0, 0, "", ans);
    for (const auto& s : ans) {
        std::cout << s << std::endl;
    }
}
