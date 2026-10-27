#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 5);
    vector<vector<int>> dp(n + 5, vector<int>(k + 5, 0));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= min(a[i], k); j++) {
            for (int m = j; m <= k; m++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][m] + max(m, j));
            }
        }
    }

    int res = 0;
    for (int i = 0; i <= k; i++) {
        res = max(res, dp[n][i]);
    }
    cout << res << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
