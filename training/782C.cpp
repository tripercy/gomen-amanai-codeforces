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
const int MAXN = 2e5 + 5;

int n, u, v;
int color[MAXN], vis[MAXN];
vector<int> edges[MAXN];
set<int> used[MAXN];

void dfs(int u) {
    vis[u] = 1;

    int c = 1;
    for (int v : edges[u]) {
        if (vis[v]) {
            continue;
        }
        while (c == color[u] || used[u].find(c) != used[u].end()) {
            c++;
        }
        color[v] = c;
        used[u].insert(c);
        used[v].insert(color[u]);
        dfs(v);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    memset(color, -1, sizeof(color));
    memset(vis, 0, sizeof(vis));
    color[1] = 1;
    dfs(1);
    int maxk = 1;
    for (int i = 1; i <= n; i++) {
        maxk = max(maxk, color[i]);
    }
    cout << maxk << endl;
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
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
