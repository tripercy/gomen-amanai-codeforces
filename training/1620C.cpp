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
    int n, k, x;
    string s;
    cin >> n >> k >> x >> s;
    string res = "";
    int cnt = 0;
    x--;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a') {
            if (cnt > 0) {
                res += string(x % (cnt * k + 1), 'b');
                x /= cnt * k + 1;
                cnt = 0;
            }
            res += 'a';
        } else {
            cnt++;
        }
    }
    if (cnt > 0) {
        res += string(x % (cnt * k + 1), 'b');
    }
    cout << string(res.rbegin(), res.rend()) << endl;
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
