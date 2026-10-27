#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1, 1), s(n + 1);
    a[0] = 0;
    s[0] = 0;
    int target = 1;
    for (int i = 1; i <= n; i++) {
        if (i == r) {
            a[i] = (s[r - 1] ^ s[l - 1]);
        } else {
            while ((target ^ s[i - 1]) == a[i - 1]) {
                target++;
            }
            a[i] = (target ^ s[i - 1]);
            target++;
        }
        s[i] = (s[i - 1] ^ a[i]);
    }
    // for (int l = 1; l <= n; l++) {
    //     for (int r = l + 1; r <= n; r++) {
    //         if ((s[r] ^ s[l - 1]) == 0) {
    //             cout << l << " " << r << endl;
    //         }
    //     }
    // }
    for (int i = 1; i <= n; i++) {
        int x = a[i];
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
