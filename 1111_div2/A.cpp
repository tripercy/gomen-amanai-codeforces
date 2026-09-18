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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt += x == 1;
    }
    int div = n / 2;
    if (n % 2 || (div % 2 != cnt % 2)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
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
