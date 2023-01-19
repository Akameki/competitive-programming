#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// the problem during contest was that I didn't store the square root as an int, so the judge thought a lot of numbers were perfect squares when they are not. 
// however, I got a TLE when I fixed that, so it wouldn't have mattered anyway.

void solve() {
    ll nn;
    cin >> nn;
    int n = nn;
    int max = 1;
    while (n >>= 1) {
        max <<= 1;
    }
    max <<= 1;
    vector<ll> count(max, 0);
    count[0] = 1;
    ll odds = 0;
    n = nn;
    int a, curr_xor = 0;
    while (n--) {
        cin >> a;
        curr_xor ^= a;
        for (ll i = 0; i*i < max; ++i) {
            odds += count[curr_xor ^ (i*i)];
        }
        ++count[curr_xor];
    }
    ll all = nn * (nn + 1) / 2;
    cout << all - odds << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    
    return 0;
}