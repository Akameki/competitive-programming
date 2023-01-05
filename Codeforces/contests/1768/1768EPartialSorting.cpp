#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

// Not complete.

void solve() {
    ll n, M;
    cin >> n >> M;
    // permutation of 1..3n, split into left middle right
    // number of ways permutations of 1..n: n!
    // total number of permutations: (3n)!
    ll nfact = 1;
    for (ll i = 1; i <= n; ++i) {
        nfact = nfact * i % M;
    }
    ll n2fact = nfact;
    for (ll i = n + 1; i <= 2 * n; ++i) {
        n2fact = n2fact * i % M;
    }
    ll n3fact = n2fact;
    for (ll i = 2 * n + 1; i <= 3 * n; ++i) {
        n3fact = n3fact * i % M;
    }

    cerr << nfact << " " << n2fact << " " << n3fact << endl;
    // number of permutations s.t. fully sorted
    ll ops0 = 1;
    // number of permutations s.t. left or right are sorted
    ll ops1 = 2 * n2fact - nfact;
    ops1 -= ops0;
    // number of permutations s.t. numbers in left stay in left, OR numbers in right stay in right
    ll ops2 = 2 * nfact * n2fact % M - nfact * nfact % M * nfact % M;
    ops2 -= ops1;
    // remaining permutations
    ll ops3 = n3fact - ops0 - ops1 - ops2;
    cerr << ops0 << " " << ops1 << " " << ops2 << " " << ops3 << endl;

    ll ans = ops1 + 2*ops2 + 3*ops3;
    ans %= M;
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