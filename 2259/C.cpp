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
    vector<int> a(n), b(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int f = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            f = 1;
        } else if (a[i] == -1) {
            if (!f) {
                a[i] = 1;
            }
            break;
        }
    }
    f = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            f = 1;
        } else if (a[i] == -1) {
            if (!f) {
                a[i] = 1;
            }
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            a[i] = 0;
        }
        cout << a[i] << " ";
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
