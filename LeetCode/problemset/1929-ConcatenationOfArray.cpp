#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums);
        for (int i : nums) {
            ans.push_back(i);
        }
        return ans;
    }
};