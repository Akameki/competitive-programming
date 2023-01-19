#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

// TLE Pretest 14

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<int> ok(n + 1, 1);
    int cnt = n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        for (int z = 1; z <= n; ++z) {
            if (!ok[z]) continue;
            if ((a[i] - 1) / z > (b[i] - 1) / z) {
                ok[z] = 0;
                --cnt;
            }
        }
    }

    cout << cnt << endl;
    for (int z = 1; z <= n; ++z)
        if (ok[z]) cout << z << " ";
    cout << endl;
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