// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>

const int maxn = 2e5 + 5;
int n, a[maxn], t, m, b[maxn], k, c[maxn];

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    c[n + 1] = 0;
    for (int i = n; i >= 1; i--) {
        c[i] = c[i + 1] + a[i] / b[i];
    }

    for (int i = 1; i <= n; i++) {
        int res = k - c[i + 1];
        res = max(res, 0ll);
        if (k > c[i] || a[i] - b[i] * res < 0) {
            cout << "0 ";
        } else {
            cout << res << " ";
            k -= res;
        }
    }
    return 0;
}
