#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll mod = 998244353;

signed main() {
    ll m;
    cin >> m;
    m--;
    ll ans = 1, t = 2;
    while (m) {
        if (m & 1) ans = ans * t % mod;
        t = t * t % mod;
        m >>= 1;
    }
    cout << ans << endl;
}