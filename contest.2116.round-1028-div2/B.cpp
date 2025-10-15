#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int MAXN = 1e5 + 5;
const ll MOD = 998244353;
int p[MAXN], q[MAXN], r[MAXN];

ll exp2(int i) {
    ll res = 1;
    ll base = 2;
    while (i > 0) {
        if (i % 2) {
            res *= base;
            res %= MOD;
        }
        base *= base;
        base %= MOD;
        i /= 2;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    int maxp = -1, maxq = -1, ip = -1, iq = -1;
    for (int i = 0; i < n; i++) {
        if (p[i] > maxp) {
            maxp = p[i];
            ip = i;
        }
        if (q[i] > maxq) {
            maxq = q[i];
            iq = i;
        }
        if (maxp > maxq || (maxp == maxq && q[i - ip] > p[i - iq])) {
            r[i] = (exp2(p[ip]) + exp2(q[i - ip])) % MOD;
        } else {
            r[i] = (exp2(p[i - iq]) + exp2(q[iq])) % MOD;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << r[i] << " ";
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
