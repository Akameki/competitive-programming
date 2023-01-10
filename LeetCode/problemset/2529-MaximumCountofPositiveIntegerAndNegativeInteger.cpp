#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int maximumCount(vector<int>& nums) {
       int pos = 0, neg = 0;
        for (int v : nums)
            if (v < 0) ++neg;
            else if (v > 0) ++pos;
        return max(neg, pos);
    }
};