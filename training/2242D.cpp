#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    a = " " + a;
    b = " " + b;
    vector<int> pfsa, pfsb;
    pfsa.push_back(0);
    pfsb.push_back(0);
    for (int i = 1; i <= n; i++) {
        pfsa.push_back((pfsa[i - 1] + a[i] - '0') % 10);
    }
    for (int i = 1; i <= m; i++) {
        pfsb.push_back((pfsb[i - 1] + b[i] - '0') % 10);
    }
    if (pfsa[n] != pfsb[m]) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> dp(n + 5, vector<int>(m + 5, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1]));
            if (pfsa[i] == pfsb[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
        }
    }
    cout << dp[n][m] << endl;
}

int32_t main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    int TEST = 1;
    if (MULTITEST) {
        dbg(TEST);
        TEST++;
        cin >> t;
    }
    while (t--) {
        solve();
    }

    return 0;
}
