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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<bool> vis(n + 1, false);
    stack<pii> st;
    st.push({1, 0});
    int cnt = 0;
    vis[1] = true;
    while (!st.empty()) {
        auto [u, p] = st.top();
        st.pop();
        for (int v : edges[u]) {
            if (v == p) {
                continue;
            }
            if (vis[v]) {
                if (cnt == 1) {
                    cout << u << " " << v << endl;
                    cout << "NO\n";
                    return;
                }
                cnt++;
                continue;
            }
            vis[v] = true;
            st.push({v, u});
        }
    }
    cout << (cnt == 1 ? "FHTAGN!\n" : "NO\n");
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
