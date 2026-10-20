#include <bits/stdc++.h>
#include <climits>
#include <deque>
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

#define int long long
#define ll long long
using pii = pair<int, int>;

int cal(pii l, int x) { return l.first * x + l.second; }

int check(pii l1, pii l2, pii l3) {
    return (long double)(l2.second - l1.second) * (l2.first - l3.first) >=
           (long double)(l1.first - l2.first) * (l3.second - l2.second);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), dp(n, INT_MAX);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    deque<pii> segs;
    dp[0] = 0;
    segs.push_back({b[0], 0});
    for (int i = 1; i < n; i++) {
        while (segs.size() >= 2 && cal(segs[0], a[i]) > cal(segs[1], a[i])) {
            segs.pop_front();
        }
        dp[i] = cal(segs[0], a[i]);

        pii seg = {b[i], dp[i]};
        while (segs.size() >= 2 &&
               check(segs[segs.size() - 2], segs[segs.size() - 1], seg)) {
            segs.pop_back();
        }
        segs.push_back(seg);
    }
    cout << dp[n - 1];
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
