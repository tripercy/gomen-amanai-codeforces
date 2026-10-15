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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, priority_queue<int>> mp;
    unordered_map<int, int> steps;
    int res = INT_MAX;
    for (int x : a) {
        int step = 0;
        while (x > 0) {
            if (mp[x].size() == k) {
                if (mp[x].top() > step) {
                    steps[x] -= mp[x].top();
                    steps[x] += step;
                    mp[x].pop();
                    mp[x].push(step);
                }
            } else {
                mp[x].push(step);
                steps[x] += step;
            }

            if (mp[x].size() == k) {
                res = min(res, steps[x]);
            }

            step++;
            x >>= 1;
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
