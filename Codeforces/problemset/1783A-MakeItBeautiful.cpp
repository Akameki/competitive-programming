#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

// didn't need to keep track of min/max because input sorted

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (a[0] == a[n - 1]) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        cout << a[n-1] << " " << a[0] << " ";
        for (int i = 1; i < n - 1; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
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