#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, m, k, l;
    cin >> n >> m >> k >> l;
    vector<vector<ll>> I(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> P(n + 1, vector<ll>(m + 1));
    vector<vector<ll>> K(n + 1, vector<ll>(m + 1));
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> I[i][j];
        }
    }
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= m; j++) {
            P[i][j] = I[i][j] + P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }
    ll nn = n - k, mm = m - l;
    for (ll i = 1; i <= k; i++) {
        for (ll j = 1; j <= l; j++) {
            K[i][j] = P[i + nn][j + mm] - P[i - 1][j + mm] - P[i + nn][j - 1] + P[i - 1][j - 1];
        }
    }

    ll max_sum = 0;
    for (ll i = 1; i <= k; i++) {
        for (ll j = 1; j <= l; j++) {
            max_sum += llabs(K[i][j]);
        }
    }
    cout << max_sum << endl;
}