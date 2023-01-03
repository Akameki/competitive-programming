#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> hair(n);
    unordered_map<int, int> razors_needed;
    unordered_set<int> set; // set of all elements in lows
    stack<int> cutting; // strictly decreasing
    bool bad = false;
    for (int i = 0; i < n; ++i) {
        cin >> hair[i];
    }
    for (int i = 0; i < n; ++i) {
        int goal;
        cin >> goal;
        if (hair[i] < goal) {
            bad = true; // can't add hair
        } else {
            while (!cutting.empty() && cutting.top() < goal) {
                set.erase(cutting.top());
                ++razors_needed[cutting.top()];
                cutting.pop();
            }
            if (hair[i] > goal && !set.count(goal)) {
                set.insert(goal);
                cutting.push(goal);
            }
        }
    }
    while (!cutting.empty()) {
        ++razors_needed[cutting.top()];
        cutting.pop();
    }

    int m;
    cin >> m;
    while (m--) {
        int a;
        cin >> a;
        if (razors_needed.count(a)) {
            --razors_needed[a];
            if (razors_needed[a] == 0) {
                razors_needed.erase(a);
            }
        }
    }
    if (!razors_needed.empty() || bad) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
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