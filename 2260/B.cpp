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
    int x, y, k;
    cin >> x >> y >> k;
    int cy = y, cx = x;
    if (cy == cx) {
        cout << "0\n";
        return;
    }
    int res = 0;
    while (cy % cx != cy - cx && k > 0){
        k--;
        res += cy % cx;
        cy++;
        cx++;
    }
    dbg(res);
    dbg(cy);
    dbg(cx);
    res += (cy - cx) * k;
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
