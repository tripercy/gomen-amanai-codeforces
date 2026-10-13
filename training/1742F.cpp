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

#define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int q;
    cin >> q;
    bool flag = false, flag2 = false;

    int l1 = 0, l2 = 0;
    while (q--) {
        int o, k;
        string s;
        cin >> o >> k >> s;
        if (flag) {
            cout << "YES\n";
            continue;
        }
        for (char c : s) {
            if (c != 'a') {
                if (o == 1) {
                    flag2 = true;
                } else {
                    flag = true;
                }
            }
        }
        if (flag) {
            cout << "YES\n";
            continue;
        }
        if (flag2) {
            cout << "NO\n";
            continue;
        }
        o == 1 ? l1 += k * s.size() : l2 += k * s.size();
        cout << (l1 < l2? "YES\n" : "NO\n");
    }
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
