#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

// FAILED PRETEST 4

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
// ^   ^   ^   ^   ^    ^     ^     ^
void solve() {
    int n;
    cin >> n;
    ll a;
    unordered_set<ll> s;
    bool dup = 0;
    int mod2[2] = {0};
    int mod6[6] = {0};
    while (n--) {
        cin >> a;

        if (s.count(a)) dup = 1;
        else s.insert(a);

        ++mod2[a%2];
        ++mod6[a%6];
    } 

    // debug
    // cout << dup << "|";
    // cout << mod2[0] << "," << mod2[1] << "|";
    // for (int v : mod6) {
    //     cout << v << ",";
    // }
    // only 1 value of mod2 can be greater than 1
    if (dup || (mod2[0] > 1 && mod2[1] > 1)) {
        cout << "NO" << endl;
    } else if ((mod6[1] > 1 && mod6[3] > 1 && mod6[5] > 1) || (mod6[2] > 1 && mod6[4] > 1 && mod6[0] > 1)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() { // FAILS PRETESTS
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}