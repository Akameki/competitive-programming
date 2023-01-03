#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int mx = 1;
        
        for (int v : s) {
            if (s.find(v-1) == s.end()) { // no v-1? v is start of sequence
                int lmax = 1;
                while (s.find(++v) != s.end()) {
                    ++lmax;
                }
                mx = max(mx, lmax);
            }
        }

        return mx;
    }
};