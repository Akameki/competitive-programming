#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        else if (n == 1) return {"()"};
        else {
            vector<string> strs;
            for (int i = 0; i < n; ++i) {
                for (string left : generateParenthesis(n - i - 1)) {
                    for (string right : generateParenthesis(i)) {
                        strs.push_back(right + "(" + left + ")");
                        // strs.push_back("(" + left + ")" + right);
                    }
                }

            }
            return strs;
        }
    }
};