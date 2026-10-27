#include <bits/stdc++.h>
#include <climits>

#define int long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pfs(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pfs[i] = pfs[i - 1] + a[i];
    }
    int ans = INT_MIN, mxl = INT_MIN;
    for (int i = 1; i <= n; i++) {
        mxl = max(mxl, pfs[i - 1] - i * (i - 1));
        ans = max(ans, mxl + i * (i + 1) - pfs[i]);
    }
    cout << pfs[n] + ans << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
