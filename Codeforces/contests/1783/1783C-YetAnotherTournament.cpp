#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

// struct to pass to sort pairs by: prefer smaller first value
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> og;
    vector<pair<int,int>> vec;
    unordered_set<int> used;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        og.push_back(x);
        vec.push_back({x, i + 1});
    }
    sort(vec.begin(), vec.end(), cmp());
    int beat = 0;
    if (m < vec[0].first) {
        cout << n+1 << endl;
        return;
    }
    // can beat 2? choose lowest
    for (int i = 0; i < n - 1; ++i) {
        if (m >= vec[i].first + vec[i+1].first) {
            ++beat;
            m -= vec[i].first;
            used.insert(vec[i].second);
        } else {
            ++beat;
            // last win, try to beat player with same amount of wins to tie
            if (used.count(beat + 1) || m >= og[beat]) {
                cout << n - beat << endl;
            } else {
                cout << n - beat + 1 << endl;
            }
            return;
        }
    }
    // can we beat the last one?
    if (m >= vec[n-1].first) {
        cout << 1 << endl;
    } else {
        if (used.count(n)) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
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