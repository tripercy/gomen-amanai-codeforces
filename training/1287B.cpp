#include <bits/stdc++.h>
#include <unordered_map>
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
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    unordered_map<string, bool> mp;
    char tp[3] = {'S', 'E', 'T'};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string target(k, 'S');
            for (int c = 0; c < k; c++) {
                if (a[i][c] == a[j][c]) {
                    target[c] = a[i][c];
                } else {
                    int id = 0;
                    while (tp[id] == a[i][c] || tp[id] == a[j][c]) {
                        id++;
                        id %= 3;
                    }
                    target[c] = tp[id];
                }
            }
            if (mp[target]) {
                res++;
            }
        }
        mp[a[i]] = true;
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
