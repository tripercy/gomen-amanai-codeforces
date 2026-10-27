#include <climits>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;
const int MAXN = 3e5 + 5;
int n, m;
ll a[MAXN], b[MAXN], pfs[MAXN];

void solve() {
    cin >> n >> m;
    pfs[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pfs[i] = a[i] + pfs[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    vector<vector<int>> dp(n + 5, vector<int>(m + 5, INT_MAX));
    for (int j = 1; j <= m; j++) {
        int l = 1, s = 0;
        dp[0][j] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i][j] = dp[i][j - 1];
            s += a[i];
            while (s > b[j] && l <= i) {
                s -= a[l];
                l++;
            }
            if (l > i) {
                continue;
            }
            dp[i][j] = min(dp[i][j], dp[l - 1][j] + m - j);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << (dp[n][m] == INT_MAX || dp[n][m] < 0 ? -1 : dp[n][m]) << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
