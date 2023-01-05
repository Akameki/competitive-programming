#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    int move = 0;
    int expect = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (a == expect) {
            ++expect;
        } else {
            ++move;
        }
    }
    int ans = move / k + (move % k != 0);
    cout << ans << endl;
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