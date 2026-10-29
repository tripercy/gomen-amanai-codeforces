#include <bits/stdc++.h>
#include <climits>
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

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> d(n + 5), pfs(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        d[i] = s[i] == '(' ? 1 : -1;
    }
    for (int i = 1; i <= n; i++) {
        pfs[i] = pfs[i - 1] + d[i];
    }
    vector<pii> peaks;
    for (int i = 1; i < n; i++) {
        if (pfs[i] > pfs[i - 1] && pfs[i] > pfs[i + 1]) {
            peaks.push_back({pfs[i], i});
        }
    }
    int dist = INT_MAX;
    for (int i = 0; i < peaks.size() - 1; i++) {
        if (peaks[i].first >= peaks[i + 1].first) {
            continue;
        }
        int d = peaks[i + 1].second - peaks[i].second - peaks[i + 1].first +
                peaks[i].first;
        dbg(i);
        dbg(peaks[i].first);
        dbg(peaks[i].second);
        dbg(peaks[i + 1].first);
        dbg(peaks[i + 1].second);

        dist = min(dist, d);
    }
    if (dist == INT_MAX) {
        cout << -1 << endl;
        return;
    }
    cout << n - dist << endl;
}

int32_t main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    int TEST = 1;
    if (!MULTITEST) {
        solve();
        return 0;
    }
    cin >> t;
    while (t--) {
        dbg(TEST);
        TEST++;
        solve();
    }

    return 0;
}
