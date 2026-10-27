#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#define int long long

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int s = 0, lev = 0;
    int res = 0;
    vector<int> ord;

    int l = 0, r = n - 1;
    while (l <= r) {
        int newlev = (s + a[r]) / x;
        if (newlev > lev) {
            ord.push_back(a[r]);
            lev = newlev;
            s += a[r];
            res += a[r];
            r--;
        } else {
            ord.push_back(a[l]);
            s += a[l];
            l++;
        }
    }

    cout << res << endl;
    for (int x : ord) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
