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
    s = " " + s;
    int l = 1, r = n;
    vector<int> res;
    while (l < r) {
        if (s[r] == '1') {
            r--;
            continue;
        }
        if (s[l] == '1') {
            res.push_back(l);
            res.push_back(r);
            r--;
            l++;
            continue;
        }
        l++;
    }
    sort(res.begin(), res.end());
    if (res.size() == 0) {
        cout << "Bob\n";
        return;
    }
    cout << "Alice\n" << res.size() << endl;
    for (int c : res) {
        cout << c << " ";
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
