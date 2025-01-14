#include <algorithm>
#include <iostream>
#include <vector>

#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        // if (k == 0) {
        //     cout << a[0] << endl;
        //     continue;
        // }
        int res = a[0] * n;
        for (int i = 0; i < n; i++) {
            int price = b[i];
            int cnt = n - i;
            int earn = price * cnt;
            int bad = cnt - (n - (lower_bound(a.begin(), a.end(), price) - a.begin()));
            if (bad <= k) {
                // cout << price << " " << bad << " " << earn << endl;
                res = max(res, earn);
            }
        }
        for (int i = 0; i < n; i++) {
            int price = a[i];
            int cnt = n - (lower_bound(b.begin(), b.end(), price) - b.begin());
            int earn = cnt * price;
            int bad = cnt - (n - i);
            if (bad <= k) {
                // cout << price << " " << bad << " " << earn << endl;
                res = max(res, earn);
            }
        }
        cout << res << endl;
    }
}
