#include <bits/stdc++.h>

using namespace std;
const int MAXN = 3e5 + 5;
int a[MAXN], b[MAXN], x[MAXN], y[MAXN], z[MAXN], c[MAXN];

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[i] = b[i];
    }
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i] >> z[i];
    }
    for (int i = q; i > 0; i--) {
        int cz = c[z[i]];
        c[z[i]] = 0;
        c[x[i]] = max(c[x[i]], cz);
        c[y[i]] = max(c[y[i]], cz);
    }
    for (int i = 1; i <= n; i++) {
        a[i] = c[i];
    }
    for (int i = 1; i <= q; i++) {
        c[z[i]] = min(c[x[i]], c[y[i]]);
    }
    for (int i = 1; i <= n; i++) {
        if (b[i] != c[i]) {
            // for (int i = 1; i <= n; i++) {
            //     cout << c[i] << " ";
            // }
            // cout << endl;
            cout << -1 << "\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
