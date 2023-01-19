#include <iostream>

using namespace std;

int main() {
    int r=0;
    int a,b,c,d,e;
    int ans;
    while (1) {
        cin >> a>>b>>c>>d>>e;
        if (a==1 || e == 1) { ans = 2; break; } 
        else if (b==1 || d==1) { ans = 1; break; } 
        else if (c==1) { ans = 0; break; } 
        r++;
    }
    if (r==0 || r==4) ans+=2;
    else if (r==1 || r==3) ans += 1;
    cout << ans;
    return 0;
}