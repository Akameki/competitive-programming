#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k, el;
    cin >> n >> k;
    vector<int> v;
    while (n--) {
        cin >> el;
        v.push_back(el);
    }
    int kth = v[k - 1];

    int i = k-1;
    if (kth > 0) {
        while (++i < v.size() && v[i] == kth) {}
        cout << i;
    } else {
        while (--i >= 0 && v[i] == 0) {}
        cout << i + 1;
    }
    return 0;
}