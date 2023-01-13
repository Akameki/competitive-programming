#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans; // dp
        ans.push_back(0);
        for (int i = 1; i <= n; ++i) {
            ans.push_back(ans[i >> 1] + (i & 1));
        }
        return ans;
    }
};