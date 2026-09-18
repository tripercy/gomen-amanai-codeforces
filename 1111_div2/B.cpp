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
    ll n, m, k;
    cin >> n >> k >> m;
    if (k > m) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << m - k + 1;
    for (int i = 1; i < n; i++) {
        cout << " 1";
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
