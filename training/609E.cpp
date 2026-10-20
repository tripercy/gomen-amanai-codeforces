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
int n, m;
int in[MAXN], out[MAXN], a[MAXN], par[22][MAXN], weights[22][MAXN], h[MAXN], q,
    timer = 0;
vector<pii> edges[MAXN], adj[MAXN];

void dfs(int u, int p, int w) {
    in[u] = ++timer;
    par[0][u] = p;
    weights[0][u] = w;
    for (auto [v, w] : adj[u]) {
        if (v == p)
            continue;
        h[v] = h[u] + 1;
        dfs(v, u, w);
    }
    out[u] = timer;
}

int get_max_to_ancestor(int u, int ancestor) {
    int ans = 0;
    for (int i = 20; i >= 0; i--) {
        if (h[u] - (1 << i) >= h[ancestor]) {
            ans = max(ans, weights[i][u]);
            u = par[i][u];
        }
    }
    return ans;
}

bool check(int u, int v) { return (in[u] <= in[v] && out[v] <= out[u]); }

int lca(int u, int v) {
    if (check(u, v))
        return u;
    if (check(v, u))
        return v;
    for (int i = 21; i >= 0; i--) {
        if (par[i][u] && !check(par[i][u], v))
            u = par[i][u];
    }
    return par[0][u];
}

void solve() {
    cin >> n >> m;
    vector<pii> queries;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        queries.push_back({u, v});
    }
    int res = 0;
    map<pii, bool> inMst;
    // MST
    //
    // LCA prep
    h[1] = 1;
    dfs(1, 0, 0);
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= n; j++) {
            par[i][j] = par[i - 1][par[i - 1][j]];
            weights[i][j] =
                max(weights[i - 1][j], weights[i - 1][par[i - 1][j]]);
        }
    }

    for (auto [u, v] : queries) {
        if (inMst[{u, v}] || inMst[{v, u}]) {
            cout << res;
        } else {
            int p = lca(u, v);
            int tmp = res;
            tmp -= max(get_max_to_ancestor(u, p), get_max_to_ancestor(v, p));
            cout << tmp;
        }

        cout << "\n";
    }
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
