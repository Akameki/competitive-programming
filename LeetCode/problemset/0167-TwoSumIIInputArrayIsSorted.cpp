#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int num = numbers[left] + numbers[right];
            if (num < target) {
                ++left;
            } else if (num == target) {
                return {left + 1, right + 1};
            } else {
                --right;
            }
        }
        return {-1, -1};
    }
};