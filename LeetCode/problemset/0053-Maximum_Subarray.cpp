#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        int sum = 0;
        for (int &n : nums) {
            sum = max(n, sum + n);
            ans = max(ans, sum);
        }
        return ans;
    }
};