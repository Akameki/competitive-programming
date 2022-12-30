#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int concatenatedBinary(int n) {
        const long long m = 1e9 + 7;
        // assert(m == 1'000'000'007);
        long long i = 0;
        long long ans = 0;
        int len = 1; // len of i in binary
        int times = 0; // how many times we've shifted ans len times
        while(++i <= n) {
            if (times < (1 << (len - 1))) // there are 2^(len-1) numbers with length len in binary
                ++times;
            else {
                ++len;
                times = 1;
            }
            ans <<= len;
            ans %= m;
            ans += i;
        }
        return ans % m;
    }
};