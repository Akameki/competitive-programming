#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(begin(points), end(points));
        int i = 0;
        int ans = 0;
        while (i < points.size()) {
            ++ans;
            int stop_at = points[i++][1];
            while (i < points.size() && points[i][0] <= stop_at) {
                stop_at = min(stop_at, points[i][1]);
            }
        }
        return ans;
    }
};