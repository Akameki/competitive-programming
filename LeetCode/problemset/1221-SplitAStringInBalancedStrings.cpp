#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int balancedStringSplit(string s) {
        int r = 0, l = 0;
        int ans = 0;
        for (char c : s) {
            if (c == 'R') r++;
            else l++;
            if (r != 0 && r == l) {
                ans++;
                r = l = 0;
            }
        }
        return ans;
    }
};