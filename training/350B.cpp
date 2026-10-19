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
    int n;
    cin >> n;
    vector<int> t(n + 1), par(n + 1), out(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> par[i];
        out[par[i]]++;
    }
    int k = 0;
    vector<int> path;
    for (int i = 1; i <= n; i++) {
        if (t[i] == 0) {
            continue;
        }
        vector<int> tmp{i};
        int cnt = 1;
        int curr = i;
        while (par[curr] != 0 && out[par[curr]] == 1) {
            curr = par[curr];
            cnt++;
            tmp.push_back(curr);
        }
        if (cnt > k) {
            k = cnt;
            path = tmp;
        }
    }
    cout << k << endl;
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
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
