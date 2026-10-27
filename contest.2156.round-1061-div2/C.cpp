#include <algorithm>
#include <iostream>

using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n + 1]);
    for (int x = a[n]; x > 1; x--) {
        int cnt = lower_bound(&a[1], &a[n + 1], 4 * x) - &a[1];
        for (int i = 1; i < 4; i++) {
            int m = upper_bound(&a[1], &a[n + 1], x * i) -
                    lower_bound(&a[1], &a[n + 1], x * i);
            // cout << x * i << " " << m << " " << cnt << endl;
            cnt -= m;
        }
        if (cnt <= k) {
            cout << x << endl;
            return;
        }
    }
    cout << 1 << endl;
    return;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
