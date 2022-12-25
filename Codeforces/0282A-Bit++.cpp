#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int ans=0;
    string s;
    while (n--) {
        cin >> s;
        if (s[1]=='-') {
            ans--;
        } else ans++;
    }
    cout << ans;
    return 0;
}