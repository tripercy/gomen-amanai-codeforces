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

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int res = 1;
    int last = s[0];
    int cnt = 1;
    int f1 = 0, f2 = 0;
    for (int i = 1; i < n - 1; i++) {
        if (s[i - 1] != s[i] && s[i + 1] != s[i]) {
            f1 = 1;
            break;
        }
    }
    dbg(res);
    for (int i = 1; i < n; i++) {
        if (s[i] == last) {
            cnt++;
        } else {
            if (cnt > 2) {
                f2 = 1;
                break;
            }
            last = s[i];
            cnt = 1;
        }
    }
    if (cnt > 2) {
        f2 = 1;
    }
    cout << res + f1 + f2 << endl;
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
