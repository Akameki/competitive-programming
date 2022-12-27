#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> grid = vector<vector<int>>(n, vector<int>(n, 0));
        uint16_t nn = n*n;
        uint8_t r = 0, c = -1, i;
        uint16_t s = 0;
        --n;
        while (s != nn) {
            grid[r][++c] = ++s;
            for (i = 0; i < n; ++i) grid[r][++c] = ++s;
            for (i = 0; i < n; ++i) grid[++r][c] = ++s;
            for (i = 0; i < n; ++i) grid[r][--c] = ++s;
            for (i = 1; i < n; ++i) grid[--r][c] = ++s;
            n -= 2;
        }
        return grid;
    }
};