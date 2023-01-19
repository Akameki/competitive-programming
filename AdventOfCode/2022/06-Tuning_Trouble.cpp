#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("input", "r", stdin);

    queue<char> q1; unordered_map<char, int> s1;
    queue<char> q2; unordered_map<char, int> s2;

    int ans1 = 0;
    int i = 0;
    char c;
    while (++i) {
        cin >> c;
        q1.push(c);
        q2.push(c);
        s1[c]++;
        s2[c]++;
        if (!ans1 && q1.size() > 4) {
            if (--s1[q1.front()] == 0)
                s1.erase(q1.front());
            q1.pop();
            if (s1.size() == 4) {
                ans1 = 1;
                cout << i << endl;
            }
        }
        if (q2.size() > 14) {
            if (--s2[q2.front()] == 0)
                s2.erase(q2.front());
            q2.pop();
            if (s2.size() == 14) {
                cout << i << endl;
                break;
            }
        }
    }

    return 0;
}