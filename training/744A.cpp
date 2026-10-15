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

#define int long long
#define ll long long
using pii = pair<int, int>;

const int NMAX = 1005;

int par[NMAX], sz[NMAX];

int get_par(int u) {
    if (par[u] == u) {
        return u;
    }
    int p = get_par(par[u]);
    par[u] = p;
    return p;
}

int join(int u, int v) {
    u = get_par(u);
    v = get_par(v);
    if (sz[u] < sz[v]) {
        swap(u, v);
    }
    if (u == v) {
        return u;
    }
    par[v] = u;
    sz[u] += sz[v];
    return u;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }

    int u, v;
    vector<pii> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        join(u, v);
        edges[i] = {u, v};
    }
    set<int> gov;
    map<int, int> edge_count;
    for (int i = 0; i < k; i++) {
        gov.insert(get_par(a[i]));
    }
    for (auto &[u, v] : edges) {
        edge_count[get_par(u)]++;
    }
    int vcount = 0, ecount = 0;
    set<int> vis;
    dump(gov);
    for (int i = 1; i <= n; i++) {
        int p = get_par(i);
        dbg(i);
        dbg(p);
        if (gov.find(p) == gov.end() && vis.find(p) == vis.end()) {
            vcount += sz[p];
            ecount += edge_count[p];
            vis.insert(p);
        }
    }
    int res = 0;
    int e2 = 0;
    dbg(vcount);
    dbg(ecount);
    for (int p : gov) {
        int l = sz[p] + vcount;
        int max_edge = sz[p] * (sz[p] - 1) / 2;
        e2 += max_edge - edge_count[p];
        int r = max_edge + ecount;
        dbg(l);
        dbg(r);
        int tmp = l * (l - 1) / 2 - r;
        res = max(res, tmp);
    }
    cout << res + e2 << "\n";
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
