#include <iostream>

using namespace std;

int main() {
    long long n, m, a, ans;
    cin >> n >> m >> a;
    n = n/a + (n%a != 0);
    m = m/a + (m%a != 0);
    ans = n*m;
    cout << ans;
    return 0;
}