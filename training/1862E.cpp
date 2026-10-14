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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    int res = 0;
    int s = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            if (pq.size() < m) {
                pq.push(a[i]);
                s += a[i];
                res = max(res, s - d * i);
            } else if (a[i] > pq.top()) {
                s -= pq.top();
                pq.pop();
                s += a[i];
                pq.push(a[i]);
                res = max(res, s - d * i);
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
