#include <algorithm>
#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#define dump(a)                                                                \
    do {                                                                       \
        cout << "[DBG] " << #a << ": ";                                        \
        for (auto &x : a)                                                      \
            cout << x << " ";                                                  \
        cout << endl;                                                          \
    } while (0)
#else
#define dbg(x)
#define dump(a)
#endif

#define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 5), pfs(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    unordered_map<int, vector<int>> mp;
    mp[0].push_back(0);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        pfs[i] = pfs[i - 1] + a[i];
        int x = pfs[i] % k;
        int d =
            upper_bound(mp[x].begin(), mp[x].end(), i - k - 1) - mp[x].begin();
        res += d;
        dbg(i);
        dbg(pfs[i]);
        dbg(d);
        mp[x].push_back(i);
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
