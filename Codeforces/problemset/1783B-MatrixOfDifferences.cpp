#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> trow(n);
    int lo = 0;
    int hi = n*n + 1;
    bool par = true;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < n; ++j) {
                cout << (par ? ++lo : --hi) << " ";
                par = !par;
            }
            cout << endl;
        } else {
            for (int j = n - 1; j >= 0; --j) {
                trow[j] = (par ? ++lo : --hi);
                par = !par;
            };
            for (int j = 0; j < n; ++j) {
                cout << trow[j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}