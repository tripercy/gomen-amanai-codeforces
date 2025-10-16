#include <bits/stdc++.h>

using namespace std;
const int MAXN = 10;
int a[MAXN];
int n;

void solve() {
    cin >> n;
    int flg = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            flg = 1 - flg;
        } else if (a[i] == 0) {
            res++;
        }
    }
    res = flg * 2;
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
