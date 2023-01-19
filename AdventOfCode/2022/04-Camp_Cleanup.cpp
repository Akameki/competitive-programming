#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("input", "r", stdin);

  string line;
  int ans = 0;
  int ans2 = 0;
  while (getline(cin, line)) {
    if (line.empty())
      break;
    replace(line.begin(), line.end(), ',', ' ');
    replace(line.begin(), line.end(), '-', ' ');
    stringstream ss(line);
    int a1, a2, b1, b2;
    ss >> a1 >> a2 >> b1 >> b2;
    if (a1 >= b1 && a2 <= b2) { // b contains a
      ans++;
    } else if (b1 >= a1 && b2 <= a2) {
      ans++;
    }

    if ((a1 >= b1 && a1 <= b2) || (b1 >= a1 && b1 <= a2)) {
      ans2++;
    }
  }
  cout << ans << endl;
  cout << ans2 << endl;
  return 0;
}