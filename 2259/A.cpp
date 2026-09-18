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
    int n, k;
    string s;
    cin >> n >> k >> s;
    int l = n / k;
    int res = 0;
    for (int i = 0; i < l; i++) {
        int cnt = 0;
        for (int j = 0; j < k; j++) {
            cnt += s[i * k + j] == '1';
        }
        res += (cnt == k);
    }
    cout << res << endl;
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
