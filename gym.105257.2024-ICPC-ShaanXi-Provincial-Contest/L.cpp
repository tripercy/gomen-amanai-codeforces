#include <bits/stdc++.h>
using namespace std;

#define ll long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        ll ans = 2;
        while (true) {
            if (x % ans != 0) {
                break;
            }
            ans++;
        }
        cout << ans << endl;
    }
}