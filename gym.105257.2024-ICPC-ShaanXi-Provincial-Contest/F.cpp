#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
const int maxn = 2e5 + 5;
int n, a[maxn], t, m;
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        int mx = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]);
        cout << (mx & mx) << "\n";
    }
    return 0;
}
