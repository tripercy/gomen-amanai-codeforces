#include <bits/stdc++.h>
#define MULTITEST true
#define MOD 998244353
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

#define int long long
// #define ll long long
using pii = pair<int, int>;

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    dbg(s);
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for (int i = 1; i <= n; i++) {
        if (i <= r) {
            p[i] = min(r - i, p[l + (r - i)]);
        }
        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    string aug = "";
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++) {
        s[i] == '0' ? c0++ : c1++;
        aug += string("#") + s[i];
    }
    aug += "#";
    dbg(c0);
    dbg(c1);
    int res = (c0 * (c0 - 1)) / 2;
    res += (c1 * (c1 - 1)) / 2;
    res++;
    dbg(res);
    vector<int> p = manacher_odd(aug);
    for (int i = 0; i < p.size(); i++) {
        int x = p[i];
        dbg(x);
        res -= (x - 1) / 2;
    }
    res %= MOD;
    cout << res << endl;
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
