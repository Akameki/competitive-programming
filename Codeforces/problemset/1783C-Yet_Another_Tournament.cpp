#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

// didn't need to store index, or "used" set

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> og;
    vector<int> vec;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        og.push_back(x);
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    int beat = 0;
    if (m < vec[0]) { // beat 0, last place
        cout << n+1 << endl;
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        if (m >= vec[i] + vec[i+1]) { // we can beat the next two
            ++beat;
            m -= vec[i];
        } else { // we can only beat next..
            ++beat;
            // did we beat player with same amount of wins to tie?
            if (m >= og[beat]) {
                cout << n - beat << endl;
            } else {
                cout << n - beat + 1 << endl;
            }
            return;
        }
    }
    // can we beat the last one?
    if (m >= vec[n-1]) {
        cout << 1 << endl;
    } else {
        if (m >= og[n - 1]) {
            cout << n - beat << endl;
        } else {
            cout << n - beat + 1 << endl;
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