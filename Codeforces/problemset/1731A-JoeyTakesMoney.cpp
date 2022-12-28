#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--) {
        int n, n2;
        cin >> n;
        n2 = n;
        long long ans = 1;
        while (n--) {
            int a;
            cin >> a;
            ans *= a;
        }
        cout << (ans+n2-1) * 2022 << endl;
    }
    return 0;
}