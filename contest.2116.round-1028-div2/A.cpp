#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (min(a, c) >= min(b, d)) {
        cout << "Gellyfish\n";
    } else {
        cout << "Flower\n";
    }
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
