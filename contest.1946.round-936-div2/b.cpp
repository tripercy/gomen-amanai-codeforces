#include <iostream>
#include <vector>

using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    const int MOD = 1e9 + 7;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> pfs(n + 1);
        int res = 0;
        int mx = 0;
        for (int i = 0; i < n; i++) {
            res += a[i] % MOD;
            res %= MOD;
            pfs[i + 1] = pfs[i] + a[i];
            pfs[i + 1] = max(0ll, pfs[i + 1]);
            // pfs[i + 1] %= MOD;
            mx = max(mx, pfs[i + 1]);
        }
        // cout << res << " " << mx << endl;
        for (int i = 0; i < k - 1; i++) {
            res += mx;
            mx = (mx * 2) % MOD;
            // cout << mx << endl;
            res %= MOD;
        }
        res = (res + mx) % MOD;
        while (res < 0) {
            res += MOD;
        }
        cout << res << endl;
    }
}
