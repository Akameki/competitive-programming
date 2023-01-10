#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    string reverseVowels(string s) {
        int left = 0, right = s.size() - 1;
        bool vowels[128] = {0};
        for (char c : "aeiouAEIOU") vowels[c] = 1;
        while (true) {
            while (left < right && !vowels[s[left]]) ++left;
            while (left < right && !vowels[s[right]]) --right;
            if (left < right) {
                swap(s[left], s[right]);
                ++left;
                --right;
            } else {
                return s;
            }
        }
    }
};