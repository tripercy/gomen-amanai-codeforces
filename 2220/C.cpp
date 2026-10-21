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
    int p, q;
    cin >> p >> q;
    int maxm = max(p, q);

    int s = p + 2 * q;
    for (int m = 2; m * m <= s; m++) {
        int n = (s + m) / (2 * m - 1);
        if (2 * m * n - (m + n) == s &&
            (n - 1) * (m - 1) + min(n - 1, m - 1) >= q && n >= 2) {
            cout << m - 1 << " " << n - 1 << endl;
            return;
        }
    }

    cout << -1 << endl;
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
