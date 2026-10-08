#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#else
#define dbg(x)
#endif

#define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n), dp(n, 1);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i < n; i++) {
        dp[i] += dp[i - 1];
        if (p[i] < p[i - 1]) {
            dp[i] += i;
        }
    }
    int res = 0;
    for (int x : dp) {
        res += x;
    }
    cout << res << endl;
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
