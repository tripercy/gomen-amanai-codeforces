#include <bits/stdc++.h>
#include <vector>
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

const int NMAX = 2e5 + 5;
int l[NMAX], r[NMAX];
vector<int> child[NMAX];

int dfs(int u) {
    int steps = 0;
    int lim = 0;
    for (int v : child[u]) {
        steps += dfs(v);
        lim += r[v];
    }
    if (lim < l[u]) {
        steps++;
    } else {
        r[u] = min(r[u], lim);
    }
    return steps;
}

void solve() {
    int n;
    cin >> n;
    int p;
    for (int i = 1; i <= n; i++) {
        child[i] = vector<int>();
    }
    for (int i = 2; i <= n; i++) {
        cin >> p;
        child[p].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
    }
    cout << dfs(1) << endl;
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
