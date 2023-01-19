#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums[0] < nums[nums.size() - 1]) return nums[0];
        int l = 0, r = nums.size() - 1;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (nums[l] > nums[m]) {
                r = m;
            } else {
                l = m;
            }
        }
        return nums[r];
    }
};