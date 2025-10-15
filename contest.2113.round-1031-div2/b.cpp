#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void solve() {
    int w, h, a, b;
    int x1, y1, x2, y2;
    cin >> w >> h >> a >> b;
    cin >> x1 >> y1 >> x2 >> y2;

    int dw = abs(x1 - x2);
    int dh = abs(y1 - y2);
    if (dw == a || dh == b) {
        cout << "YES\n";
        return;
    }
    if ((dw > a && (dw - a) % a == 0) || (dh > b && (dh - b) % b == 0)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
