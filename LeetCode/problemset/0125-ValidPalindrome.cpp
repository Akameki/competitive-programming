#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    bool isPalindrome(string s) {
        auto it1 = s.begin();
        auto it2 = s.end() - 1;
        while (it1 < it2) {
            // cout << *it1 << " vs " << *it2 << endl;
            if (!isalnum(*it1)) ++it1;
            else if (!isalnum(*it2)) --it2;
            else if (tolower(*it1++) != tolower(*it2--)) return false;
        }
        return true;
    }
};