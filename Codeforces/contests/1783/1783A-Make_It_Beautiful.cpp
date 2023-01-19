#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int max = 0; int maxi;
    int min = 200; int mini;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] > max) {
            max = a[i];
            maxi = i;
        }
        if (a[i] < min) {
            min = a[i];
            mini = i;
        }
    }
    if (min == max) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        cout << max << " " << min << " ";
        for (int i = 0; i < n; ++i) {
            if (i != maxi && i != mini) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
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