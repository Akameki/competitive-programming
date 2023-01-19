#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    // O(n) 1-pass time, O(1) space
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum_all = 0;
        int small_sum = 0;
        int min_sum = 0;
        int large_sum = 0;
        int max_sum = nums[0];
        
        for (int &i : nums) {
            sum_all += i;
            small_sum = min(0, small_sum + i);
            min_sum = min(min_sum, small_sum);
            large_sum = max(i, large_sum + i);
            max_sum = max(max_sum, large_sum);
        }
        if (sum_all == min_sum) return max_sum;
        return max(max_sum, sum_all - min_sum);
    }


    // O(n) 2-pass time, O(n) space
    // int maxSubarraySumCircular(vector<int>& nums) {
    //     int pref = nums[0];
    //     vector<int> pref_max = {pref}; // max prefix sum
        
    //     int best_sum = max(nums[0], 0); // noncircular subarray sum
    //     int ans = best_sum;

    //     bool has_pos = nums[0] > 0;
    //     int mx = nums[0];
    //     for (int i = 1; i < nums.size(); ++i) { // fill pref_max, and max non-circular subarray
    //         pref += nums[i];
    //         pref_max.push_back(max(pref_max[i - 1], pref));
    //         best_sum = max(best_sum + nums[i], 0);
    //         ans = max(ans, best_sum);
    //         mx = max(mx, nums[i]);
    //         if (nums[i] > 0) has_pos = true;
    //     }
        
    //     if (!has_pos) return mx;

    //     int suff = nums[nums.size() - 1];
    //     int suff_max = suff; // max suffix
    //     for (int i = nums.size() - 2; i >= 1; --i) {
    //         ans = max(ans, pref_max[i - 1] + suff_max);
    //         suff += nums[i];
    //         suff_max = max(suff_max, suff);
    //     }
    //     return ans;
    // }
};