#include <bits/stdc++.h>
#define MULTITEST false
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#else
#define dbg(x)
#endif

#define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int g = gcd(x, y);
    x /= g;
    y /= g;

    int ar = 0, br = 0;

    int a1 = x * (a / x);
    int b1 = a1 / x * y;
    if (b1 <= b) {
        ar = a1;
        br = b1;
    }

    b1 = y * (b / y);
    a1 = b1 * x / y;
    if (a1 <= a && a1 * b1 > ar * br) {
        ar = a1;
        br = b1;
    }
    cout << ar << " " << br << endl;
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
