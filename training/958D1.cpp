#include <bits/stdc++.h>
#define MULTITEST false
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
    int m;
    cin >> m;
    map<pii, int> mp;
    vector<pii> id(m + 5);
    int a, b, c, s, g;
    for (int i = 1; i <= m; i++) {
        char _;
        cin >> _ >> a >> _ >> b >> _ >> _ >> c;
        s = a + b;
        g = gcd(s, c);
        s /= g;
        c /= g;
        mp[{s, c}]++;
        id[i] = {s, c};
    }
    for (int i = 1; i <= m; i++) {
        cout << mp[id[i]] << " ";
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
