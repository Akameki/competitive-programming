#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class UF {
private:
    vector<int> par;
    vector<int> size;
public:
    UF(int n) {
        for (int i = 0; i < n; ++i) par.push_back(i);
        size = vector<int>(n, 1);
    }
    int find(int n) {
        while (n != par[n])
            n = par[n] = par[par[n]];
        return n;
    }
    void merge(int a, int b) {
        int p1 = find(a), p2 = find(b);
        if (p1 == p2) return;
        if (size[p1] < size[p2]) {
            par[p1] = p2;
            size[p2] += size[p1];
        } else {
            par[p2] = p1;
            size[p1] += size[p2];
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<vector<int>> adj(vals.size());
        for (vector<int> &e : edges) {
            int a = e[0], b = e[1];
            if (vals[a] >= vals[b]) adj[a].push_back(b);
            if (vals[b] >= vals[a]) adj[b].push_back(a);
        }

        map<int, vector<int>> by_val;
        for (int i = 0; i < vals.size(); ++i) by_val[vals[i]].push_back(i);

        UF uf(vals.size());
        int ans = vals.size();
        for (auto &[val, nodes] : by_val) {

            for (int n : nodes)
                for (int neib : adj[n])
                    uf.merge(n, neib);
            
            unordered_map<int, int> cnt;
            for (int n : nodes) {
                ans += cnt[uf.find(n)]++;
            }
        }

        return ans;
    }
};