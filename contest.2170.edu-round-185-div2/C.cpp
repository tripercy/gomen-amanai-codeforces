#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> q(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    sort(q.begin(), q.end());
    sort(r.begin(), r.end());
    int i = 0, j = n - 1;
    int res = 0;
    while (i < n && j >= 0) {
        int tmp = q[i] * (r[j] + 1) + r[j];
        if (tmp <= k) {
            res++;
            i++;
            j--;
        } else {
            j--;
        }
    }
    cout << res << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
