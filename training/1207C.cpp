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

#define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n, a, b;
    string s;
    cin >> n >> b >> a >> s;
    s = " " + s;
    int r1 = a, r2 = LONG_LONG_MAX;
    for (int i = 1; i <= n; i++) {
        dbg(r1);
        dbg(r2);
        int t1 = LONG_LONG_MAX, t2 = LONG_LONG_MAX;
        if (s[i] == '0') {
            if (r1 != LONG_LONG_MAX) {
                t1 = r1 + a + b;
                t2 = r1 + 2 * a + 2 * b;
            }
            if (r2 != LONG_LONG_MAX) {
                t1 = min(t1, r2 + a + 2 * b);
                t2 = min(t2, r2 + 2 * a + b);
            }
        } else {
            t2 = r2 + 2 * a + b;
            t1 = LONG_LONG_MAX;
        }
        r1 = t1;
        r2 = t2;
    }
    cout << r1 << endl;
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
