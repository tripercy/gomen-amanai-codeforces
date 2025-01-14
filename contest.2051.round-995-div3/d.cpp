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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        sort(a.begin(), a.end());
        int res = 0;
        for (int i = 0; i < n; i++) {
            int l = lower_bound(a.begin() + i, a.end(), sum - a[i] - y) - a.begin();
            int r = upper_bound(a.begin() + i, a.end(), sum - a[i] - x) - a.begin();
            l = max(i + 1, l);
            // cout << i << " " << l << " " << r << " " << sum - a[i] - x << " " << sum - a[i] - y << endl;
            if (l > r || i == r) {
                break;
            }
            res += r - l;
        }
        cout << res << endl;
    }
}
