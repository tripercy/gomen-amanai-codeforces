#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
#define int long long

#define MOD 998244353

int inv(int a, int b)
{
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int Pow(int a, int b)
{
    int ans = 1;
    while (b > 0) {
        if (b % 2)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

int32_t main()
{
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    // std::cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<pair<int, int>> a(n), b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i].first;
            b[i].second = i;
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<int> ia(n), ib(n);

        int res = 1;
        for (int i = 0; i < n; i++) {
            res *= min(a[i].first, b[i].first);
            res %= MOD;
            ia[a[i].second] = i;
            ib[b[i].second] = i;
        }
        res %= MOD;
        cout << res;
        for (int i = 0; i < q; i++) {
            int o, x;
            cin >> o >> x;
            x--;
            if (o == 1) {
                int u = ia[x];
                // res = res * inv(min(a[u].first, b[u].first), MOD) % MOD;
                res = res * Pow(min(a[u].first, b[u].first), MOD - 2) % MOD;
                res %= MOD;
                a[u].first++;
                int v = lower_bound(a.begin() + u + 1, a.end(), pair<int, int>(a[u].first, 0)) - a.begin();
                v--;
                if (v > u) {
                    // res = res * inv(min(a[v].first, b[v].first), MOD) % MOD;
                    res = res * (Pow(min(a[v].first, b[v].first), MOD - 2) % MOD);
                    res %= MOD;
                    swap(a[u], a[v]);
                    swap(ia[a[u].second], ia[a[v].second]);

                    res *= (min(a[u].first, b[u].first) % MOD * min(a[v].first, b[v].first) % MOD) % MOD;
                    res %= MOD;
                } else {
                    res *= min(a[u].first, b[u].first);
                    res %= MOD;
                }
            } else {
                int u = ib[x];
                // res = res * inv(min(a[u].first, b[u].first), MOD) % MOD;
                res = res * (Pow(min(a[u].first, b[u].first), MOD - 2) % MOD);
                res %= MOD;
                b[u].first++;
                int v = lower_bound(b.begin() + u + 1, b.end(), pair<int, int>(b[u].first, 0)) - b.begin();
                v--;
                // cout << x << " " << v << endl;
                if (v > u) {
                    // res = res * inv(min(a[v].first, b[v].first), MOD) % MOD;
                    res = res * Pow(min(a[v].first, b[v].first), MOD - 2) % MOD;
                    res %= MOD;
                    swap(b[u], b[v]);
                    swap(ib[b[u].second], ib[b[v].second]);

                    res *= (min(a[u].first, b[u].first) % MOD * min(a[v].first, b[v].first) % MOD) % MOD;
                    res %= MOD;
                } else {
                    res *= min(a[u].first, b[u].first);
                    res %= MOD;
                }
            }
            // for (int i = 0; i < n; i++) {
            //     cout << a[i].first << " ";
            // }
            // cout << endl;
            // for (int i = 0; i < n; i++) {
            //     cout << b[i].first << " ";
            // }
            // cout << endl;
            res %= MOD;
            cout << " " << res;
        }
        cout << "\n";
        // for (int i = 0; i < n; i++) {
        //     cout << a[i].first << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < n; i++) {
        //     cout << b[i].first << " ";
        // }
        // cout << endl;
    }
}
