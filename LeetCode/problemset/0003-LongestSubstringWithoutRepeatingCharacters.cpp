#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int ans = 0;
        int start = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (mp.count(c) && mp[c] >= start) {
                ans = max(ans, i - start);
                start = mp[c] + 1;
            } else {
                ans = max(ans, i - start + 1);
            }
            mp[c] = i;
        }
        return ans;
    }
};