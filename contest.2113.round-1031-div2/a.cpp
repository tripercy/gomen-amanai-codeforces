#include <bits/stdc++.h>
#include <utility>

using namespace std;

void solve() {
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;

    if (x > y) {
        swap(a, b);
        swap(x, y);
    }

    int na = 0;
    if (k >= a) {
        na = (k - a + x) / x;
    }
    k = k - na * x;
    int nb = 0;
    if (k >= b) {
        nb = (k - b + y) / y;
    }

    int res = na + nb;
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
