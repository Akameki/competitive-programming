#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
#define endl '\n'

// TLE Test 7

void solve() {
    int n;
    cin >> n;
    vector<int> goal(n);
    vector<int> ans(n);
    vector<int> ans2(n);
    unordered_set<int> used;
    unordered_set<int> used2;

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        goal[i] = a;
        if (used.count(a)) {
            if (used2.count(a)) ok = false;
            else {
                ans2[i] = a;
                used2.insert(a);
            }
        } else {
            ans[i] = a;
            used.insert(a);
        }
        used.insert(a);
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    // fill gaps in ans <= goal
    for (int i = 0; i < n; ++i) {
        if (ans[i] == 0) {
            for (int j = goal[i]; j > 0; --j) {
                if (!used.count(j)) {
                    ans[i] = j;
                    used.insert(j);
                    break;
                }
            }
        }
        if (ans2[i] == 0) {
            for (int j = goal[i]; j > 0; --j) {
                if (!used2.count(j)) {
                    ans2[i] = j;
                    used2.insert(j);
                    break;
                }
            }
        }
        if (ans[i] == 0 || ans2[i] == 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << ans2[i] << " ";
    }
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