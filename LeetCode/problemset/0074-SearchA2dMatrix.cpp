#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rlen = matrix[0].size();
        int s = 0, e = matrix.size() * rlen - 1;
        while (s <= e) {
            int m = (s + e) / 2;
            int v = matrix[m / rlen][m % rlen];

            if (v == target) return true;
            if (v > target) e = m - 1;
            else s = m + 1;
        }
        return false;
    }
};