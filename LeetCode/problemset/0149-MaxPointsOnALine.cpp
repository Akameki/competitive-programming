#include <bits/stdc++.h>
using namespace std;
/* LeetCode submission follows below. */

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        struct hashie {
            size_t operator() (const pair<int, int> &v) const {
                hash<int> hasher;
                return hasher((v.first * 31) ^ v.second);
            }
        };
        int ans = 1;
        for (int i = 0; i < points.size(); ++i) {
            unordered_map<pair<int, int>, int, hashie> mp;
            int lmax = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                // simplify rise/run
                int dy = points[j][1] - points[i][1];
                int dx = points[j][0] - points[i][0];
                if (dx == 0) {
                    lmax = max(lmax, ++mp[{0, 0}]);
                } else {
                    if (dx < 0) {
                        dy = -dy; dx = -dx;
                    }
                    int g = gcd(dy, dx);
                    lmax = max(lmax, ++mp[{dy/g, dx/g}]);
                }
            }
            ans = max(lmax + 1, ans);
        }
        return ans;
    }
};