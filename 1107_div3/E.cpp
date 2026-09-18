#include <bits/stdc++.h>
#include <cstdint>
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

int dfs(int par, int curr, vector<vector<int>> &edges, vector<int> &sizes,
        vector<int> &up) {
    sizes[curr] = 1;
    up[curr] = par;
    if (edges[curr].size() == 1 && par != -1) {
        return sizes[curr];
    }
    for (int neighbor : edges[curr]) {
        if (neighbor != par) {
            sizes[curr] += dfs(curr, neighbor, edges, sizes, up);
        }
    }
    return sizes[curr];
}

int get_child_size(vector<int> &sizes, int n, int root, int u) {
    if (sizes[root] > sizes[u]) {
        return sizes[u];
    }
    return n - sizes[root];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 5), sizes(n + 5), up(n + 5);
    vector<vector<int>> edges(n + 5, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(-1, 1, edges, sizes, up);

    int res = 0;
    int res2 = 0;
    for (int u = 1; u <= n; u++) {
        int sq = sqrt(a[u]);
        if (sq * sq != a[u] || edges[u].size() < 2) {
            continue;
        }
        int e1 = 0;
        int e2 = 0;
        int e3 = 0;
        for (int v : edges[u]) {
            int sz_v = get_child_size(sizes, n, u, v);
            e3 += e2 * sz_v;
            e2 += e1 * sz_v;
            e1 += sz_v;
        }
        res += e2;
        res2 += e3;
    }
    dbg(res);
    dbg(res2);
    cout << res + res2 << endl;
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
