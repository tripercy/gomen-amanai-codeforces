#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        cout << 9 << endl;
        return;
    }
    int x = n * n + n * n - 1 + n * n - 2 + n * n - n - 1;
    int y = n * n - 2 * n - 1 + n * n - n - 2 + n * n - n - 1 + n * n - n +
            n * n - 1;
    cout << max(x, y) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
