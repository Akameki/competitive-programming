#include <iostream>
#include <sstream>
#include <deque>
#include <string>
#include <vector>

using namespace std;

vector<deque<char>> stacks;
vector<deque<char>> stacks2;

void parse(string line) {
    for (int i = 0; i < stacks.size(); ++i) {
        int j = i * 4 + 1;
        if (line[j] != ' ') {
            stacks[i].push_front(line[j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("input", "r", stdin);

    string line;
    getline(cin, line);
    stacks.resize((line.length() + 1) / 4);
    parse(line);

    while (getline(cin, line)) {
        if (line[1] == '1') break;
        parse(line);
    }
    getline(cin, line);

    stacks2 = stacks;

    int n, a, b;
    string t;

    while (cin >> t) {
        cin >> n >> t >> a >> t >> b;
        a--;
        b--;
        stacks2[b].insert(stacks2[b].end(), stacks2[a].end()-n, stacks2[a].end());
        stacks2[a].erase(stacks2[a].end()-n, stacks2[a].end());
        while (n--) {
            char el = stacks[a].back();
            stacks[a].pop_back();
            stacks[b].push_back(el);
        }
    }

    for (auto s : stacks) {
        cout << s.back();
    }
    cout << endl;

    for (auto s : stacks2) {
        cout << s.back();
    }
    cout << endl;
    return 0;
}