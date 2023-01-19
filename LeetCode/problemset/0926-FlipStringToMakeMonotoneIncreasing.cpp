#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0;
        for (char &c : s) {
            if (c == '0') ++flips;
        }
        int ans = flips;
        for (char &c : s) {
            if (c == '0') ans = min(ans, --flips);
            else ++flips;
        }
        return ans;
    }
};