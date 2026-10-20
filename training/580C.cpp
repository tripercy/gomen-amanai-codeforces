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
const int MAXN = 1e5 + 5;
int n, m, res;
int has_cat[MAXN], vis[MAXN];
vector<int> edges[MAXN];

void dfs(int u, int cnt) {
    vis[u] = 1;
    if (has_cat[u]) {
        cnt++;
    } else {
        cnt = 0;
    }
    if (cnt > m) {
        dbg(u);
        return;
    }
    if (u != 1 && edges[u].size() == 1) {
        res++;
    }
    for (int v : edges[u]) {
        if (vis[v]) {
            continue;
        }
        dfs(v, cnt);
    }
}

void solve() {
    cin >> n >> m;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++) {
        cin >> has_cat[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    res = 0;
    dfs(1, 0);
    cout << res << endl;
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
