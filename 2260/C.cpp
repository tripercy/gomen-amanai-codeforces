#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

#define int long long
// #define ll long long
using pii = pair<int, int>;

void solve() {
    int x, y;
    cin >> x >> y;
    int res = x + y;
    int m = log2(res) + 1;
    int steps = 0;

    int a = 0, b = 0;
    for (int i = m; i >= 0; i--) {
        int br = (res >> i) & 1;
        if (br == 1) {
            if (a + (1 << i) > x) {
                b |= (1 << i);
            } else {
                a |= (1 << i);
            }
        } else {
            if (a + (1 << i) <= x && b + (1 << i) <= y) {
                a |= (1 << i);
                b |= (1 << i);
            }
        }
    }

    cout << res << " " << (x - a) << endl;
}

int32_t main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    if (MULTITEST) {
        cin >> t;
    }
    while (t--) {
        solve();
    }

    return 0;
}
