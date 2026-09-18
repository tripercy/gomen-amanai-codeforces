#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt += a[i] == 0;
    }
    if (cnt == 1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            if (!(f % 2)) {
                cout << 'A';
            } else {
                cout << 'B';
            }
            f = min(2, f + 1);
        } else {
            cout << 'C';
        }
    }
    cout << "\n";
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    if (MULTITEST) {
        cin >> t;
    }
    while (t--) {
        solve();
    }

    return 0;
}
