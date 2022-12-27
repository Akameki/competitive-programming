#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    // alternative solution, use unordered_map<char, int> instead of array and translating char to index
    vector<string> commonChars(vector<string>& words) {
        int common[26] = {0};
        for (char c: words[0]) {
            ++common[c - 'a'];
        }
        for (int i = 1; i < words.size(); ++i) {
            int need[26];
            copy(begin(common), end(common), begin(need));
            for (char c: words[i]) {
                --need[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                while (need[i]-- > 0) {
                    --common[i];
                }
            }
        }
        vector<string> ans;
        for (int i = 0; i < 26; ++i) {
            while (common[i]--) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
    }
};