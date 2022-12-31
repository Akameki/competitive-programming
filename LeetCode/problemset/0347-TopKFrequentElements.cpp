#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> freq; // freq, num
        unordered_map<int, int> m; // num -> idx

        for (int v : nums) {
            if (m.find(v) != m.end()) {
                ++freq[m[v]].first;
            } else {
                m[v] = freq.size();
                freq.push_back({1, v});
            }
        }
        sort(freq.begin(), freq.end(), greater<>());

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};