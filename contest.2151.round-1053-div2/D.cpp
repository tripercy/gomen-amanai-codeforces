#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAXN = 2e5 + 5;
const ll MOD = 998244353;
ll FACT[MAXN];

ll expbase(ll base, ll e) {
    ll res = 1;
    while (e > 0) {
        if (e & 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        e >>= 1;
    }
    return res % MOD;
}

ll choose(int n, int r) {
    return (FACT[n] * expbase((FACT[r] * FACT[n - r]) % MOD, MOD - 2)) % MOD;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (a[0] < 2 || sum != n) {
        // cout << "a" << endl;
        cout << 0 << endl;
        return;
    }
    for (int i = (n + 1) / 2; i < n; i++) {
        if (a[i] != 0) {
            // cout << "b" << endl;
            cout << 0 << endl;
            return;
        }
    }
    int left = 0 - n % 2;
    int res = 1;
    for (int r = (n - 1) / 2; r > 0; r--) {
        left += 2;
        if (a[r] > left) {
            // cout << "c" << endl;
            cout << 0 << endl;
            return;
        }
        res = (res * choose(left, a[r])) % MOD;
        // cout << r << " " << left << " " << a[r] << " " << choose(left, a[r])
        //      << endl;
        left -= a[r];
    }
    cout << res % MOD << endl;
}

int main(int argc, char *argv[]) {
    FACT[0] = FACT[1] = 1;
    for (int i = 2; i < MAXN; i++) {
        FACT[i] = FACT[i - 1] * i;
        FACT[i] %= MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
