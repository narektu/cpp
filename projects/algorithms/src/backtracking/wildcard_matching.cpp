#include "../../include/backtracking/wildcard_matching.h"
#include <iostream>
#include <string>
#include <vector>

bool isMatch(std::string s, std::string p) {
    int m = s.length(), n = p.length();
    std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= n; j++) {
        if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '?' || s[i - 1] == p[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*') dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
    return dp[m][n];
}

void run_wildcard_matching() {
    std::cout << "Running Algorithm: Wildcard Matching" << std::endl;
    std::cout << "Match 'adceb' with '*a*b': " << (isMatch("adceb", "*a*b") ? "True" : "False") << std::endl;
}
