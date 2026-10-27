#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int cnt = n, sum = 0;
    for (int i = 0; i < n; i++) {
        cnt -= (b[i] == 0);
        sum += b[i];
    }
    for (int res = cnt; res > 0; res--) {
        if (sum >= res + n - 1) {
            cout << res << endl;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
