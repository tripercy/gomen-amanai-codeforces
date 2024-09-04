#include <bits/stdc++.h>
using namespace std;

#define ll long long

int hit[110][110];

void shoot(ll x, ll y, ll n, ll k, ll &to_shoot) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (hit[y][x]) return;
    hit[y][x] = 1;
    cout << x + 1 << " " << y + 1 << '\n';
    string ans;
    cin >> ans;
    if (ans != "miss") {
        to_shoot--;
        if (to_shoot == 0) exit(0);
        shoot(x + 1, y, n, k, to_shoot);
        shoot(x - 1, y, n, k, to_shoot);
        shoot(x, y + 1, n, k, to_shoot);
        shoot(x, y - 1, n, k, to_shoot);
    }
}

signed main() {
    ll n, k;
    cin >> n >> k;
    ll to_shoot = 5 * k;
    for (ll x = 0; x < n; x++) {
        for (ll y = 0; y < n; y++) {
            if ((x + y) % 5 == 4) shoot(x, y, n, k, to_shoot);
        }
    }
}