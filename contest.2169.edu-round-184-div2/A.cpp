#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, a;
    cin >> n >> a;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int cnt = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < a) {
            cnt++;
        } else if (v[i] > a) {
            cnt2++;
        }
    }
    if (cnt > cnt2) {
        cout << a - 1 << endl;
    } else {
        cout << a + 1 << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
