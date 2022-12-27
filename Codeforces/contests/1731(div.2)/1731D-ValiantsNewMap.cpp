#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    int nn, mm;
    int a;
    cin >> tt;
    while (tt--) {
        cin >> nn >> mm;
        vector<vector<int>> v(nn, vector<int>(mm, 0));
        for (int r=0; r<nn; ++r) {
            for (int c=0; c<mm; ++c) {
                cin >> a;
                v[r][c] = a;
            }
        }
        int max = 1;
        for (int r=0; r<nn; ++r) {
            for (int c=0; c<mm; ++c) {
                for (int m = max + 1; m <= min(nn-r, mm-c); ++m) {
                    bool valid = true;
                    for (int rr=r; rr < r+m; ++rr) {
                        for (int cc=c; cc < c+m; ++cc) {
                            if (v[rr][cc] < m) {
                                // cout << "max: " << m << "fail at " << rr << " " << cc;
                                valid = false;
                            }
                        }
                    }
                    if (valid) ++max;
                    else break;
                }
            }
        }
        cout << max << endl;
    }
    
    return 0;
}