#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        vector<int> sf(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        sf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sf[i] = max(sf[i + 1], a[i]);
        }

        if (b[0] < sf[0]) {
            cout << -1 << endl;
            continue;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int tmp = upper_bound(b.begin(), b.end(), sf[i], greater<int>()) - b.begin();
            if (tmp == m) {
                break;
            }

            int c = b[tmp - 1];
            int cnt = 1;
            int s = 0;
            while (i < n - 1 && sf[i] == sf[i + 1]) {
                if (s + a[i] > c) {
                    cnt++;
                    s = 0;
                }
                s += a[i];
                i++;
            }
            if (s > 0) {
                cnt++;
            }
            // cout << sf[i] << " " << cnt << " " << tmp << endl;
            res += cnt * (m - tmp);
        }
        cout << res << endl;
    }
}
