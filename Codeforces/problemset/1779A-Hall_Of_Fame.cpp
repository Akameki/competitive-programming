#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s.find("RL") != string::npos) {
        cout << 0 << endl;
    } else {
        int i = s.find("LR");
        cout << (i == string::npos ? -1 : i + 1) << endl;
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