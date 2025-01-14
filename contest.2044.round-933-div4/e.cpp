#include <iostream>

#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        int k, l1, r1, l2, r2;
        cin >> k >> l1 >> r1 >> l2 >> r2;
        int res = 0;
        int start = max(l1, l2);
        int end = min(r1, r2);

        if (start <= end) {
            res += end - start + 1;
        }

        int l = l1, r = r1;
        int nmax = (log(r2) - log(l1)) / log(k) + 1;
        for (int n = 1; n <= nmax; n++) {
            int kn = pow(k, n);
            l = l2 / kn;
            r = r2 / kn;

            int xmax = min(r1, r);
            int xmin = max(l1, l);
            if (xmin > xmax) {
                continue;
            }
            // cout << xmax << " " << xmin << endl;
            res += xmax - xmin + 1;
        }
        cout << res << endl;
    }
}
