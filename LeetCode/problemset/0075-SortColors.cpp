#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int colors[3] = {0};
        for (int n : nums) {
            ++colors[n];
        }
        int idx = 0;
        for (int i = 0; i <= 2; ++i) {
            int n = colors[i];
            while (n--) {
                nums[idx++] = i;
            }
        }
    }
};