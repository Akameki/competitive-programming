#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int most = 0;
        int start = 0, end = -1;
        int ans = 0;

        while (++end < s.size()) {
            most = max(most, ++freq[s[end] - 'A']);
            if (end - start + 1 - most > k) --freq[s[start++] - 'A'];
            else ans = end - start + 1;
        }
        return ans;
    }
};