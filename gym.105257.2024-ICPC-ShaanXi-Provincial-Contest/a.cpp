#include <bits/stdc++.h>

using namespace std;

void solve() {
    int p;
    cin >> p;
    string res (9, '-');

    for (int i = 0; i < 3; i++) {
        int xf = p % 10;
        p /= 10;
        int x = xf >> 0 & 1;
        int w = xf >> 1 & 1;
        int r = xf >> 2 & 1;
        if (x) {
            res[8 - i * 3] = 'x';
        }
        if (w) {
            res[8 - i * 3 - 1] = 'w';
        }
        if (r) {
            res[8 - i * 3 - 2] = 'r';
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
