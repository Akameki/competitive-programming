#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

#define EMPTY 0
#define FRESH 1
#define ROTTEN 2

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        unordered_set<int> queued; // r * 100 + c, because pairs don't have default hash
        deque<pair<int,int>> deq; // newly rotten oranges at current time
        int fresh = 0;
        int time = 0; 
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == ROTTEN) {
                    deq.push_back({r, c});
                    queued.insert(r * 100 + c);
                } else if (grid[r][c] == FRESH) {
                    ++fresh;
                }
            }
        }

        if (fresh == 0) return 0;

        const pair<int,int> directions[] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while (!deq.empty()) { // add all newly rotten oranges for next iteration
            if (fresh == 0) return time;
            int rotten = deq.size();
            while (rotten--) {
                auto [r, c] = deq.front();
                deq.pop_front();
                for (auto [dr, dc] : directions) {
                    int r2 = r + dr;
                    int c2 = c + dc;
                    if (0 <= r2 && r2 < rows && 0 <= c2 && c2 < cols) {
                        if (grid[r2][c2] == FRESH && !queued.count(r2 * 100 + c2)) {
                            deq.push_back({r2, c2});
                            queued.insert(r2 * 100 + c2);
                            --fresh;
                        }
                    }
                }
            }
            ++time;
        }
        return -1;
    }
};