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
    int cnto = 0, cnt2 = 0, cnt4 = 0;
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnto += x % 2;
        if (!(x % 2)) {
            cnt2 += (x / 2) % 2;
            cnt4 += !((x / 2) % 2);
        }
    }
    cout << max(cnto, max(cnt2, cnt4)) << endl;
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
