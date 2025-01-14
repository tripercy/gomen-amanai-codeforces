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
        int n, m;
        cin >> n >> m;
        vector<int> a(n, 0), b(m, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        int kev = a[0];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int j;
        for (j = 0; j < n; j++) {
            if (a[j] > kev) {
                break;
            }
        }

        vector<int> c(m);
        for (int i = 0; i < m; i++) {
            if (b[i] <= kev) {
                c[i] = 1;
            } else {
                while (j < n && a[j] < b[i]) {
                    j++;
                }
                c[i] = n - j + 1;
            }
            // cout << c[i] << " ";
        }
        // cout << endl;
        sort(c.begin(), c.end());
        for (int i = 1; i <= m; i++) {
            int res = 0;
            for (int k = i - 1; k < m; k += i) {
                res += c[k];
            }
            cout << res << " ";
        }
        cout << endl;
    }
}
