#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN];
int n;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n + 1]);
    int res = 0;
    for (int i = 1; i <= n; i += 2) {
        res = max(res, a[i + 1] - a[i]);
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
