#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(i,j, grid);
                    ++ans;
                }
            }
        }
        return ans;
    }

    void dfs(int r, int c, vector<vector<char>>& grid) {
        grid[r][c] = '0';
        for (int dir = 0; dir < 4; ++dir) {
            int nr = r + dx[dir];
            int nc = c + dy[dir];
            if (0 <= nr && nr < grid.size() && 0 <= nc && nc < grid[0].size() && grid[nr][nc] == '1') {
                dfs(nr, nc, grid);
            }
        }
    }
};