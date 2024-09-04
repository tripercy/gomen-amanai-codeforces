#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ll n, s;
    cin >> n >> s;
    vector<ll> w(n);
    for (ll &x : w) cin >> x;

    sort(w.begin(), w.end());

    ll ans = 0;
    for (ll i = 0; i < 2; i++) {
        ans++;
        w.pop_back();
        n--;
        s--;
        if (n == 0 || s == 0) break;
    }

    s *= 3;

    // binary search for k smallest-sized chargers
    ll l = 0, r = n + 1;

    auto check = [&](int mid) {
        vector<ll> par(3);
        ll sum = 0;
        for (ll i = 0; i < mid; i++) {
            sum += w[i], par[w[i] % 3]++;
        }
        ll rem = 0, to_add = abs(par[1] - par[2]);
        if (par[1] > par[2])
            rem += to_add % 2, rem += to_add / 2;
        else
            rem += to_add;

        return (sum + rem) <= s;
    };

    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    ans += l;
    cout << ans << '\n';
}