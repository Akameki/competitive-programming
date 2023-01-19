#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> set;
        // rows
        for (vector<char> row : board) {
            for (char cell : row) {
                if (cell == '.') continue;
                if (set.count(cell)) return false;
                set.insert(cell);
            }
            set.clear();
        }
        // cols
        for (int c = 0; c < 9; ++c) {
            for (int r = 0; r < 9; ++r) {
                if (board[r][c] == '.') continue;
                if (set.count(board[r][c])) return false;
                set.insert(board[r][c]);
            }
            set.clear();
        }
        // boxes
        set.clear();
        for (int i = 0; i < 9; ++i) {
            int boxr = (i / 3) * 3;
            int boxc = (i % 3) * 3;
            for (int r = boxr; r < boxr + 3; ++r) {
                for (int c = boxc; c < boxc + 3; ++c) {
                    if (board[r][c] == '.') continue;
                    if (set.count(board[r][c])) return false;
                    set.insert(board[r][c]);
                }
            }
            set.clear();
        }
        return true;
    }
};