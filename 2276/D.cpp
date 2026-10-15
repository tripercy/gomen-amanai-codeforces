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
const int MAXN = 3e5 + 5;
vector<int> children[MAXN];
bool vis[MAXN];
int dist[MAXN];

bool checkTree(int u) {
    int vcount = 0;
    vis[u] = true;
    bool isTree = true;
    for (int v : children[u]) {
        if (vis[v]) {
            vcount++;
            if (vcount > 1) {
                return false;
            }
            continue;
        }
        isTree &= checkTree(v);
    }
    return isTree;
}

void dfs(int u, int d) {
    dist[u] = d;
    for (int v : children[u]) {
        if (dist[v] != -1) {
            continue;
        }
        dfs(v, d + 1);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<bool> flag(n + 1, false);
    for (int i = 1; i <= n; i++) {
        children[i] = vector<int>();
    }
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        children[u].push_back(v);
        children[v].push_back(u);
        flag[u] = true;
        flag[v] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            cout << "Brain Melt\n";
            return;
        }
    }
    bool isTree = checkTree(1);
    if (!isTree) {
        cout << "Many\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "Many\n";
            return;
        }
    }
    dfs(1, 0);
    int u = 0, d = 0;
    for (int i = 1; i <= n; i++) {
        // cout << i << ": " << dist[i] << endl;
        if (dist[i] > d) {
            d = dist[i];
            u = i;
        }
    }
    // cout << u << " " << d << endl;
    memset(dist, -1, sizeof(dist));
    dfs(u, 0);
    d = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > d) {
            d = dist[i];
        }
    }
    if (d <= 2) {
        cout << "2\n";
        return;
    }
    cout << "Many\n";
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
