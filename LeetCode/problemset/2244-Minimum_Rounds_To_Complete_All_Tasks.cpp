#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> map;
        for (int v : tasks) 
            ++map[v];

        int ans = 0;
        for (pair<int, int> v : map) {
            if (v.second == 1) return -1;
            else ans += v.second / 3 + (v.second % 3 != 0);
        }
        return ans;
    }
};