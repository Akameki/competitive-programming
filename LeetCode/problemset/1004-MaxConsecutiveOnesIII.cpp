#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int start = 0, end = -1;
        int ans = 0;
        while (true) {
            if (++end == nums.size()) return ans;
            if (nums[end] == 0) --k;
            if (k >= 0) ++ans;
            else if (nums[start++] == 0) ++k;
        }
    }
};