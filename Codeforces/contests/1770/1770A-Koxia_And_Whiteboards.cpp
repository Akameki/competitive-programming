#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve() {
    priority_queue<int> pq;
    priority_queue<int> ops;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < m - 1; ++i) {
        int a;
        cin >> a;
        ops.push(a);
    }
    ll sum;
    cin >> sum;
    while (ops.size()) {
        pq.push(ops.top());
        ops.pop();
    }
    while (--n) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
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