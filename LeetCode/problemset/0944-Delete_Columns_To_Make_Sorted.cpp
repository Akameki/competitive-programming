#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int cols = strs[0].size();

        int ans = 0;

        for (int col = 0; col < cols; ++col) {
            for (int r = 0; r < n - 1; ++r) {
                if (strs[r][col] > strs[r + 1][col]) {
                    ++ans;
                    break;
                }
            }
        }

        return ans;
    }
};