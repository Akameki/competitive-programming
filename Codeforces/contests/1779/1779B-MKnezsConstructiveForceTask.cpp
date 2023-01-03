    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define endl '\n'


    // for odd >= 5
    // a + b + a + b + a (odd n) = a + b
    // => a + b + a (odd n-= 2) = 0
    // => (n/2 + 1 )*a + (n/2)*b = 0
    // => xa + yb = 0
    // => a = -y/x * b
    // let b = x => a = -y

    // 1 -2 1 -2 1

    void solve() {
        int n;
        cin >> n;
        if (n == 3) {
            cout << "NO" << endl;
        } else if (n % 2 == 1) {
            cout << "YES" << endl;
            int a = -(n-2) / 2;
            int b = (n-2)/2 + 1;
            while (n > 1) {
                cout << a << " " << b << " ";
                n -= 2;
            }
            cout << a << endl;
        } else {
            cout << "YES" << endl;
            while (n) {
                cout << -2 << " " << 2 << " ";
                n -= 2;
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