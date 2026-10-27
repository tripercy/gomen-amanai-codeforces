#include <iostream>
#define ll long long

using namespace std;
ll n = ((ll)1 << 35);

void solve() {
    ll x, y;
    cin >> x >> y;
    if (x == y) {
        cout << -1 << endl;
        return;
    }
    ll res = n - max(x, y);
    cout << res << endl;
    // cout << (res + x) + (res + y) << " " << ((res + x) ^ (res + y)) << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
