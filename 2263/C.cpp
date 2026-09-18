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
    vector<int> a(n);
    vector<int> res(n + 5, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        res[min(a[i] * (i + 1), n + 2)]--;
        res[min(a[i] * (i + 1) + i + 1, n + 2)]++;
    }
    for (int i = 1; i < n; i++) {
        res[i] += res[i - 1];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += res[i] >= 0;
    }
    cout << cnt << endl;
    if (cnt > 0) {
        for (int i = 0; i < n; i++) {
            if (res[i] >= 0) {
                cout << i << " ";
            }
        }
        cout << endl;
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
