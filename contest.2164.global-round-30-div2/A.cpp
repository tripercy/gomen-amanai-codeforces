#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    int mn = INT_MAX, mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    cin >> x;
    if (mx < x || mn > x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
