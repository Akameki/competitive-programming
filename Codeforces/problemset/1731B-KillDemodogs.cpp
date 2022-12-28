#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// To compute (a * b) % mod
ll mulmod(ll a, ll b, ll mod)
{
    ll res = 0; // Initialize result
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m = 1000000007;
    int tt;
    cin >> tt;
    while (tt--) {
        ll n;
        cin >> n;
        // ans = (n*(n+1)*(2*n+1))/6 + (n-1)*(n)*(n+1)/3) * 2022 mod 10^9+7
        // calculate without overflow
        ll ans = mulmod(n, n+1, m);
        ans = mulmod(ans, 2*n+1, m);
        ans = mulmod(ans, 2022/6, m);
        ll ans2 = mulmod(n-1, n, m);
        ans2 = mulmod(ans2, n+1, m);
        ans2 = mulmod(ans2, 2022/3, m);
        ans = (ans + ans2) % m;
        cout << ans << endl;
    }
    
    return 0;
}