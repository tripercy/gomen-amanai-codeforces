#include <bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  int g = gcd(x, y);
  for (int i = 0; i < n; i++) {
    if (abs((i + 1) - p[i]) % g != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  return;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
