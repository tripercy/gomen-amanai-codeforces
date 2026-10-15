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
    int n;
    string s;
    cin >> n >> s;
    string s2 = s;
    sort(s2.begin(), s2.end());
    vector<int> res(n, 0);
    int i = 0, j = 0;
    while (i < n && j < n) {
        while (j < n && s[j] != s2[i]) {
            j++;
        }
        if (j < n) {
            res[j] = 1;
            j++;
            i++;
        }
    }
    dbg(s2);
    dbg(i);
    for (int j = 0; j < n; j++) {
        if (res[j] == 0) {
            if (s[j] == s2[i]) {
                res[j] = 2;
                i++;
            } else {
                cout << "-\n";
                return;
            }
        }
    }
    for (int x : res) {
        cout << x;
    }
    cout << "\n";
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
