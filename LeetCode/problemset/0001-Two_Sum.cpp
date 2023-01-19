#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> index_of;
        for (int i = 0; i < nums.size(); ++i) {
            if (index_of.find(target - nums[i]) != index_of.end())
                return {i, index_of[target - nums[i]]};
            index_of[nums[i]] = i;
        }
        return {-1, -1};
    }
};