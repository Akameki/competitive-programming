#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    string defangIPaddr(string address) {
        return regex_replace(address, regex("\\."), "[.]");
    }
};