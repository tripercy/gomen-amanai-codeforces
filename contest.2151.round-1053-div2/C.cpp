#include <bits/stdc++.h>
#define ll long long

using namespace std;

void dumpVll(vector<ll> &v) {
    for (ll x : v) {
        cout << x << " ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(2 * n + 1);
    a[0] = 0;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> a[i];
    }
    vector<ll> pfsOdd(2 * n + 1), pfsEven(2 * n + 1), pfs(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        pfs[i] = pfs[i - 1] + a[i];
        pfsOdd[i] = pfsOdd[i - 1] + a[i] * (i % 2);
        pfsEven[i] = pfsEven[i - 1] + a[i] * (1 - i % 2);
    }
    // dumpVll(pfs);
    // dumpVll(pfsOdd);
    // dumpVll(pfsEven);
    for (int k = 1; k <= n; k++) {
        ll x = pfs[2 * n] - pfs[2 * n - k];
        ll x1;
        if (k % 2) {
            x1 = pfsEven[max(2 * n - k, 1)] - pfsEven[k];
        } else {
            x1 = pfsOdd[max(2 * n - k, 1)] - pfsOdd[k];
        }
        ll y = pfs[2 * n] - (x + x1);
        // cout << k << ": " << x << " " << x1 << " " << y << endl;
        cout << (x + x1 - y) << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
