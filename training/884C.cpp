#include <bits/stdc++.h>
#include <functional>
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

const int MAXN = 1e5 + 5;
int par[MAXN], sz[MAXN];

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
    if (u == v) {
        return u;
    }
    if (sz[u] < sz[v]) {
        swap(u, v);
    }
    par[v] = u;
    sz[u] += sz[v];
    return u;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 5);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        join(i, p[i]);
    }
    dump(p);
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i <= n; i++) {
        if (par[i] == i) {
            pq.push(sz[i]);
        }
    }
    int new_sz = pq.top();
    pq.pop();
    if (!pq.empty()) {
    }
    new_sz += pq.top();
    pq.pop();
    pq.push(new_sz);
    int res = 0;
    while (!pq.empty()) {
        int s = pq.top();
        pq.pop();
        res += s * (s - 1) + s;
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
