#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        long long s[n + 1];
        s[0] = 0;
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + a[i - 1];
        while (q--) {
            long long l, r;
            cin >> l >> r;
            l--;
            r--;
            int xl = l / n;
            int xr = r / n;
            long long res = 0;
            res += max(0, xr - xl - 1) * (long long)s[n];
            int il = l % n;
            int ir = r % n;
            if (xl == xr) {
                int a0_pos = (n - xl) % n;
                if (a0_pos <= il || a0_pos > ir) {
                    res = s[(ir + xl) % n + 1] - s[(il + xl) % n];
                } else {
                    res = (s[n] - s[(il + xl) % n]) + s[(ir + xl) % n + 1];
                }
            } else {
                // for (int i = il; i < n; i++) {
                //     res += a[(i + xl) % n];
                // }
                // for (int i = 0; i <= ir; i++) {
                //     res += a[(i + xr) % n];
                // }
                int a0_pos = (n - xl) % n;
                if (a0_pos <= il) {
                    res += s[(n + xl - 1) % n + 1] - s[(il + xl) % n];
                } else {
                    res += s[n] - s[(il + xl) % n] + s[(n + xl - 1) % n + 1];
                }

                a0_pos = (n - xr) % n;
                if (a0_pos > ir) {
                    res += s[(ir + xr) % n + 1] - s[xr];
                } else {
                    res += s[(ir + xr) % n + 1] + s[n] - s[xr];
                }
            }
            cout << res << endl;
        }
    }
}
