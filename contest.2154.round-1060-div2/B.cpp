#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e5 + 5;
int n;
int a[MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int mx = a[1];
    for (int i = 2; i <= n; i++) {
        mx = max(mx, a[i]);
        if (i % 2 == 0) {
            a[i] = mx;
        }
    }
    int res = 0;
    a[0] = a[2];
    a[n + 1] = a[n - 1];
    for (int i = 1; i <= n; i += 2) {
        res += max(0, a[i] - min(a[i - 1], a[i + 1]) + 1);
    }
    cout << res << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
