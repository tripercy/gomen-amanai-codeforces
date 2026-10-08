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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, unordered_set<int>> mp;
    for (int i = 0; i < n - 4; i++) {
        int u = a[i] + a[i + 2] - a[i + 4];
        mp[u].insert(i);
    }
    ll res = 0;
    for (auto& p : mp) {
        auto& s = p.second;
        ll sz = s.size();
        if (sz < 2) {
            continue;
        }
        res += sz * (sz - 1) / 2;
        for (int x : s) {
            if (s.find(x + 2) != s.end()) {
                res--;
            }
            if (s.find(x + 4) != s.end()) {
                res--;
            }
        }
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
