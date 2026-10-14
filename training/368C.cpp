#include <bits/stdc++.h>
#define MULTITEST false
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
    string s;
    cin >> s;
    int n = s.size(), m;
    cin >> m;
    vector<int> px(n + 1, 0), py(n + 1, 0), pz(n + 1, 0);
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        px[i] = px[i - 1] + (s[i] == 'x');
        py[i] = py[i - 1] + (s[i] == 'y');
        pz[i] = pz[i - 1] + (s[i] == 'z');
    }
    int l, r;
    dump(px);
    dump(py);
    dump(pz);
    while (m--) {
        cin >> l >> r;
        int cx = px[r] - px[l - 1];
        int cy = py[r] - py[l - 1];
        int cz = pz[r] - pz[l - 1];
        int cmax = max(cx, max(cy, cz));
        int cmin = min(cx, min(cy, cz));
        cout << (cmax - cmin > 1 && r - l + 1 > 2 ? "NO\n" : "YES\n");
    }
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
