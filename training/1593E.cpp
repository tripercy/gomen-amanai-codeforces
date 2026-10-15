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
    int n, k;
    cin >> n >> k;

    int u, v;
    set<int> leaves;
    vector<vector<int>> edges(n + 1, vector<int>());
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] <= 1) {
            leaves.insert(i);
        }
    }
    int left = n;
    while (k > 0 && !leaves.empty()) {
        k--;
        set<int> tmp;
        left -= leaves.size();
        for (int l : leaves) {
            for (int v : edges[l]) {
                deg[v]--;
                if (deg[v] == 1) {
                    tmp.insert(v);
                }
            }
        }
        leaves = tmp;
    }
    cout << left << endl;
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
