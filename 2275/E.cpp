#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> d1, d2;
    for (int i = 0; i < n - 1; i++) {
        int l1 = a[i] == b[i] ? 2 : 1;
        int l2 = a[i + 1] == b[i] ? 2 : 1;
        d1.push_back(l1 + l2);

        l1 = a[i] == b[i + 1] ? 2 : 1;
        l2 = a[i + 1] == b[i] ? 2 : 1;
        d2.push_back(l1 + l2);
    }
    vector<int> sfs(n);
    sfs[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        sfs[i] = sfs[i + 1] + d2[i];
    }
    int last = a[n - 1] == b[n - 1] ? 2 : 1;
    int res = sfs[0];
    int s = 0;
    // for (int x : d2) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // for (int x : sfs) {
    //     cout << x << " ";
    // }
    // cout << endl;
    for (int i = 0; i < n - 1; i++) {
        s += d1[i];
        // cout << s << " " << sfs[i + 1] << endl;
        res = max(res, s + sfs[i + 1]);
    }
    res = max(res, s);
    cout << res + last << endl;
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
