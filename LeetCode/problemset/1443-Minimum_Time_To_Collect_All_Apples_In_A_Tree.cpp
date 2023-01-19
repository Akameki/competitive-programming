#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
    vector<vector<int>> v;
    vector<bool> visited;
    vector<bool> a;
    int N;
    int ans;
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        v = vector<vector<int>>(n);
        visited = vector<bool>(n);
        for (vector<int> edge : edges) {
            v[edge[0]].push_back(edge[1]);
            v[edge[1]].push_back(edge[0]);
        }
        N = n;
        a = hasApple;
        dfs(0);
        return ans;
    }

    bool dfs(int curr) {
        visited[curr] = true;
        // cout << "dfs called on " << curr << endl;

        bool apple = false;
        for (int child : v[curr]) {
            if (!visited[child] && dfs(child)) {
                ans += 2;
                apple = true;
            }
        }
        return apple || a[curr];
    }
};