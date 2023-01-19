#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

// TLE Pretest 3
// can use stack for O(n+ m), see upsolve.

void solve() {
    int n;
    cin >> n;
    vector<int> ok(n); // process hair input, then bool vector
    vector<int> goal(n);
    unordered_map<int, int> razors;
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        cin >> ok[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> goal[i];
        if (ok[i] < goal[i])
            bad = true;
        else
            ok[i] = ok[i] == goal[i] ? 1 : 0;
    }
    int m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        ++razors[a];
    }
    for (int i = 0; i < n; ++i) {
        if (ok[i]) continue;
        int g = goal[i];
        if (razors[g] == 0) {
            bad = true;
            break;
        }
        for (int j = i; j < n; ++j) {
            if (goal[j] > g) break;
            if (g == goal[j]) ok[j] = 1;
        }
        --razors[g];
    }
    cout << (bad ? "NO" : "YES") << endl;
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