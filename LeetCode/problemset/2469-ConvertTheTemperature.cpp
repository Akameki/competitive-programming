#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};