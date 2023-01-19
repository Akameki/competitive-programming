#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> vals;
        for (string tok : tokens) {
            if (tok.size() > 1 || isdigit(tok[0])) {
                vals.push(stoi(tok));
            } else {
                int b = vals.top(); vals.pop();
                int a = vals.top(); vals.pop();

                if (tok == "+") vals.push(a + b);
                else if (tok == "-") vals.push(a - b);
                else if (tok == "*") vals.push(a * b);
                else vals.push(a / b);
            }
        }
        return vals.top();
    }
};