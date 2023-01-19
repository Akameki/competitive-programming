#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
private:
    int n;
    vector<vector<int>> adj;
    string labels;
    int ans;
public:
    int longestPath(vector<int>& parent, string s) {
        n = parent.size();
        adj = vector<vector<int>>(n);
        labels = s;

        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        dfs(0);
        return ans;
    }
    int dfs(int node) { // return longest chain (# nodes) starting from node
        char me = labels[node];
        int m1 = 0, m2 = 0;
        for (int a : adj[node]) {
            int res = dfs(a);
            if (me == labels[a]) continue;
            if (res > m1) {
                m2 = m1;
                m1 = res;
            } else if (res > m2) {
                m2 = res;
            }
        }
        ans = max(ans, m1 + m2 + 1);
        return m1 + 1;
    }
};