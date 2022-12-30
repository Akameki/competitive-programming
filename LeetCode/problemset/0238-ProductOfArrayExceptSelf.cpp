#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pref(nums.size());
        pref[0] = 1;
        for (int i = 1; i < nums.size(); ++i) {
            pref[i] = pref[i-1] * nums[i-1];
        }
        
        int curr_suff = 1;
        for (int i = nums.size()-2; i >= 0; --i) {
            curr_suff *= nums[i+1];
            pref[i] *= curr_suff;
            
        }
        return pref;
    }
};