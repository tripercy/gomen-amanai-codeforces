#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    int lim = 0;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> a(l);
        for (int j = 0; j < l; j++) {
            int x;
            cin >> a[j];
        }

        bool check[210000];
        memset(check, 0, 210000);
        for (int j = 0; j < l; j++) {
            if (a[j] < 210000)
                check[a[j]] = true;
        }

        bool jumped = false;
        int tmp = 0;
        for (; tmp < 210000; tmp++) {
            if (!check[tmp]) {
                if (jumped) {
                    break;
                }
                jumped = true;
            }
        }
        lim = max(lim, tmp);
    }
    long long res = (long long)lim * min(m + 1, lim + 1);
    int left = m - lim;
    if (left > 0) {
        res += (long long)left * (lim + 1 + m) / 2;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
