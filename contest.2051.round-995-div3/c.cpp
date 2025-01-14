#include <iostream>
#include <vector>

#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> a(m), q(k);
        for (int i = 0; i < m; i++)
            cin >> a[i];

        int sum = 0;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            sum += x;
        }
        int miss = n * (n + 1) / 2 - sum;
        char x = '0';
        if (k == n) {
            x = '1';
        }
        string res(m, x);
        if (k == n - 1) {
            for (int i = 0; i < m; i++) {
                if (a[i] == miss) {
                    res[i] = '1';
                }
            }
        }
        cout << res << endl;
    }
}
