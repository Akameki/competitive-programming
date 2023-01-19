#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
    vector<vector<int>> ans;
    vector<vector<int>> ivs;
    vector<int> iv;
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        ivs = intervals;
        iv = newInterval;
        
        if (intervals.empty()) { // edge case - empty intervals:
            ans.push_back(newInterval);
            return ans;
        } else if (newInterval[0] <= intervals[0][0]) { // edge case - interval is first:
            merge_push_rest(0);
            return ans;
        }

        // find two intervals surrounding the start value
        // to make O(log(n)), use binary search instead...
        int i = 0;
        while (i < intervals.size() - 1) {
            if (intervals[i][0] <= newInterval[0] && newInterval[0] <= intervals[i + 1][0]) {
                if (!overlap(newInterval, intervals[i])) ans.push_back(intervals[i++]);
                merge_push_rest(i);
                return ans;
            } else {
                ans.push_back(intervals[i++]);
            }
        }

        // edge case - interval is last:

        if (overlap(newInterval, intervals[i])) {
            ans.push_back(merge(intervals[i], newInterval));
        } else {
            ans.push_back(intervals[i]);
            ans.push_back(newInterval);
        }
        return ans;
    }

    bool overlap(vector<int> i1, vector<int> i2) {
        return i1[0] <= i2[1] && i2[1] <= i1[1] || i2[0] <= i1[1] && i1[1] <= i2[1];
    }
    vector<int> merge(vector<int> i1, vector<int> i2) {
        return {min(i1[0], i2[0]), max(i1[1], i2[1])};
    }

    void merge_push_rest(int i) {
        while (i < ivs.size() && overlap(iv, ivs[i])) {
            iv = merge(iv, ivs[i++]);
        }
        ans.push_back(iv);
        while (i < ivs.size()) {
            ans.push_back(ivs[i++]);
        }
    }
};