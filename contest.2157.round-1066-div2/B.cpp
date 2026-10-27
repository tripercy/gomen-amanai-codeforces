#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    x = abs(x);
    y = abs(y);
    if (x > n || y > n) {
        cout << "NO\n";
        return;
    }
    int cnt = 0;
    for (char c : s) {
        cnt += c == '4';
    }
    int mx = n - max(cnt - n + y, 0);
    if (mx >= x) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
