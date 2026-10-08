#include <bits/stdc++.h>
#include <climits>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#else
#define dbg(x)
#endif

#define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n), c(n), steps(n, 0);
    int l = LONG_LONG_MAX, r = LONG_LONG_MIN;
    int bound = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if (a[i] <= b[i] && b[i] <= c[i]) {
            steps[i] = min(2 * (b[i] - a[i] + 1),
                           min(2 * (c[i] - a[i] + 1), 2 * (c[i] - b[i] + 1)));
        }
        if (a[i] == b[i] && b[i] == c[i]) {
            steps[i] = k;
            bound = min(bound, a[i] * 3ll);
        }
        l = min(l, a[i] + b[i] + c[i]);
        r = max(r, a[i] + b[i] + c[i]);
    }
    r += k + 10;
    int res = l;
    while (l <= r) {
        int m = l + (r - l) / 2;
        dbg(l);
        dbg(r);
        dbg(m);
        int f = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int s = a[i] + b[i] + c[i];
            if (s >= m) {
                continue;
            }
            cnt += steps[i] + (m - s);
            if (cnt > k) {
                f = 0;
                break;
            }
        }
        if (f) {
            l = m + 1;
            res = m;
        } else {
            r = m - 1;
        }
    }
    cout << min(bound, res) << endl;
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
