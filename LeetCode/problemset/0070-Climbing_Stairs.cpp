#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 3);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            dp[i + 1] += dp[i];
            dp[i + 2] += dp[i];
        }
        return dp[n];
    }
};