#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(begin(costs), end(costs));
        for (int i = 0; i < costs.size(); ++i) {
            coins -= costs[i];
            if (coins < 0) {
                return i;
            }
        }
        return costs.size();
    }
};