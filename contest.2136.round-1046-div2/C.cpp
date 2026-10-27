#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pos(n + 1, vector<int>());
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int cnt = pos[x].size();
        if (cnt < x - 1) {
            dp[i] = dp[i - 1];
        } else {
            int j = i;
            if (x > 1) {
                j = pos[x][cnt - x + 1];
            }
            dp[i] = max(dp[i - 1], dp[j - 1] + x);
            // cout << i << " " << x << " " << j << endl;
        }
        pos[x].push_back(i);
        // cout << dp[i] << " ";
    }
    // cout << endl;
    cout << dp[n] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
