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
    int n, a, b;
    cin >> n >> a >> b;
    string states, _dir;
    cin >> states >> _dir;
    int bdir = _dir == "head" ? -1 : 1;
    cin >> states;

    a = a < b ? 1 : n;
    for (int i = 0; i < states.size(); i++) {
        char c = states[i];
        b += bdir;
        bdir *= b == 1 || b == n ? -1 : 1;
        if (c == '0') {
            if (a == b) {
                cout << "Controller " << i + 1 << "\n";
                return;
            }
        } else {
            if (b == 1) {
                a = n;
            } else if (b == n) {
                a = 1;
            } else {
                a = bdir == 1 ? 1 : n;
            }
        }
    }
    cout << "Stowaway\n";
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
