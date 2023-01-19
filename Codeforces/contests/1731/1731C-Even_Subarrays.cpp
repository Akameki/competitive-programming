#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tt;
    cin >> tt;
    while (tt--) {
        int nn;
        cin >> nn;
        vector<int> v;
        int ans = 0;
        while (nn--) {
            int a;
            cin >> a;
            v.push_back(a);
            int xorr = 0;
            for (int i = v.size()-1; i >= 0; --i) {
                xorr ^= v[i];
                if (sqrt(xorr) * sqrt(xorr) != xorr) ++ans;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}