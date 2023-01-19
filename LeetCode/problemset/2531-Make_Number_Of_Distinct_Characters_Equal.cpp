#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> ct1(26), ct2(26);
        for (char c : word1) ++ct1[c - 'a'];
        for (char c : word2) ++ct2[c - 'a'];
        
        int d1 = 0, d2 = 0;
        for (int v : ct1) if (v > 0) ++d1;
        for (int v : ct2) if (v > 0) ++d2;
        for (int i = 0; i < 26; ++i) {
            if (!ct1[i]) continue;
            for (int j = 0; j < 26; ++j) {
                if (!ct2[j]) continue;
                int nd1 = d1, nd2 = d2;
                if (i == j) {
                    if (d1 == d2) return true;
                    else continue;
                }
                if (ct1[i] == 1) --nd1;
                if (ct2[i] == 0) ++nd2;
                if (ct2[j] == 1) --nd2;
                if (ct1[j] == 0) ++nd1;
                if (nd1 == nd2) return true;
            }
        }
        return false;
    }
};