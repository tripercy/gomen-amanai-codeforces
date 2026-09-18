#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

#define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    string s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> s;
    stack<int> s1, s0;
    int res = 0;
    int c1 = 0, c0 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            c1++;
        } else {
            s0.push(c1);
            res += c1;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0) {
            c0++;
        } else {
            s1.push(c0);
        }
    }
    int d1 = 0, d0 = 0;
    cout << res;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1' && !s1.empty()) {
            int x = s1.top();
            s1.pop();
            res -= max(0ll, x - d0);
            d1++;
        } else if (s[i] == '0' && !s0.empty()){
            int x = s0.top();
            s0.pop();
            res -= max(0ll, x - d1);
            d0++;
        }
        cout << " " << res;
    }
    cout << endl;
}

int32_t main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    if (MULTITEST) {
        cin >> t;
    }
    while (t--) {
        solve();
    }

    return 0;
}
