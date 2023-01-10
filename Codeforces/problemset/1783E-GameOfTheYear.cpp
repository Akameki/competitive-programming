#include <bits/stdc++.h>
#include <type_traits>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> bad(n + 1); // 0 if okay, 1 if multiple of k cannot be this index
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        if (a[i] > b) {
            ++bad[b];
            --bad[a[i]];
        }
    }
    for (int i = 1; i <= n; ++i) {
        bad[i] += bad[i - 1];
    }
    vector<int> ans;
    for (int k = 1; k <= n; ++k) {
        bool ok = true;
        for (int m = k; m <= n; m += k) {
            if (bad[m]) {
                ok = false;
                break;
            }
        }
        if (ok) ans.push_back(k);
    }
    cout << ans.size() << endl;
    for (int v : ans) cout << v << " ";
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