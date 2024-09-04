#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

signed main() {
    string a, b;
    ll c, d;
    cin >> a >> b >> c >> d;
    ll new_a = stoll(a);

    ll gcd_cd = gcd(c, d);
    c /= gcd_cd, d /= gcd_cd;

    ll all_combs = 1ll << b.size();
    for (ll i = 0; i < all_combs; i++) {
        ll cur = 0;
        string nb;
        for (ll j = 0, ft = 1; j < b.size(); j++) {
            if (((i >> j) % 2) == 0 && (!ft || b[j] != '0')) {
                cur *= 10;
                cur += b[j] - '0';
                ft = 0;
            } else {
                nb.push_back(b[j]);
            }
        }
        if (cur == 0) continue;
        if ((cur % d) != 0) continue;
        ll ca = (cur / d);
        if (ca > new_a / c) continue;
        ca *= c;
        string chk = to_string(ca);

        ll ks = 0;
        string na;
        for (ll j = 0; j < a.size(); j++) {
            if (ks < chk.size() && a[j] == chk[ks])
                ks++;
            else
                na.push_back(a[j]);
        }
        sort(na.begin(), na.end());
        sort(nb.begin(), nb.end());

        if (ks == chk.size() && na == nb) {
            cout << "possible" << '\n';
            cout << ca << " " << cur << '\n';
            return 0;
        }
    }
    cout << "impossible" << '\n';
}