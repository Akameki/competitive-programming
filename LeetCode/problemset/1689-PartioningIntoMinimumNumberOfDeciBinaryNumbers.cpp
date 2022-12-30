#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int minPartitions(string n) {
        int len = n.size();
        int m = 0;
        while (len--) {
            m = max(m, n[len] - '0');
        }
        return m;
    }
};