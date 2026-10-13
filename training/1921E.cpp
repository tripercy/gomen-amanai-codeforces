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

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int h, w, xa, ya, xb, yb;
    cin >> h >> w >> ya >> xa >> yb >> xb;
    int dy = yb - ya;

    int da = xa > xb ? 1 : -1;
    int db = xa > xb ? -1 : 1;
    int d = dy % 2 ? db : da;
    string winner = dy % 2 ? "Alice\n" : "Bob\n";
    while (dy > 0) {
        xa = min(w, max(1, xa + d));
        dy--;
        if (xa == xb) {
            cout << winner;
            return;
        }
        xb = min(w, max(1, xb + d));
        dy--;
        if (xa == xb) {
            cout << winner;
            return;
        }
    }
    cout << "Draw\n";
}

int32_t main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    int TEST = 1;
    if (MULTITEST) {
        cin >> t;
    }
    while (t--) {
        dbg(TEST);
        TEST++;
        solve();
    }

    return 0;
}
