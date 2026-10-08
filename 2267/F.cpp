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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> res;
    res.push_back(a[n - 1] - a[0]);
    while (a[n - 1] != 0) {
        vector<int> b;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                b.push_back(a[i] ^ a[j]);
            }
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
        res.push_back(a[n - 1] - a[0]);
    }
    while(q--) {
        int x;
        cin >> x;
        cout << (x >= res.size()? res[res.size() - 1] : res[x]) << endl;
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
