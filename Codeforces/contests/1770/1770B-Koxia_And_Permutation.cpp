#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve() {
    int n, k;
    cin >> n >> k;
    int a = 1, b = n;
    while (n > 2) {
        cout << b-- << " " << a++ << " ";
        n -= 2;
    }
    if (n == 2) {
        cout << b-- << " " << a++ << " ";
    } else {
        cout << b--;
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