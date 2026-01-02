#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    ll x{};
    vector<ll> vec;
    char digit{};
    for (char ch : str) {
      if (ch >= '0' && ch <= '9') {
        if (!digit) {
          digit = true;
          vec.emplace_back(x);
          x = 0;
        }
        x *= 10;
        x += ch - '0';
      } else {
        if (digit) {
          digit = false;
          vec.emplace_back(x);
          x = 0;
        }
        x *= 26;
        x += ch - 'A' + 1;
      }
    }
    vec.emplace_back(x);
    if (vec.size() == 4) {
      x = vec[3];
      string tmp;
      while (x) {
        --x;
        tmp.push_back(x % 26 + 'A');
        x /= 26;
      }
      reverse(tmp.begin(), tmp.end());
      cout << tmp << vec[1] << '\n';
    } else {
      cout << 'R' << vec[1] << 'C' << vec[0] << '\n';
    }
  }
}
