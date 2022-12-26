#include <iostream>

using namespace std;

int a, b, c;

int main() {
    int n;
    int ans=0;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        ans += (a + b + c) >= 2;
    }
    cout << ans;
    return 0;
}