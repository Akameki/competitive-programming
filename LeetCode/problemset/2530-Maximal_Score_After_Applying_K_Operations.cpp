#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for (int v : nums) pq.push(v);
        long long ans = 0;
        while (k--) {
            ans += pq.top();
            pq.push((pq.top() + 2) / 3);
            pq.pop();
        }
        return ans;
    }
};