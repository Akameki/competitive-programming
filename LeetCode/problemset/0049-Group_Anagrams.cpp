#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> m;
        for (string s : strs) {
            string t(s);
            sort(t.begin(), t.end());
            if (m.find(t) != m.end()) {
                ans[m[t]].push_back(s);
            } else {
                m[t] = ans.size();
                ans.push_back({s});
            }
        }
        return ans;
    }
};