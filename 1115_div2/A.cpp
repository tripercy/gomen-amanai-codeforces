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
    vector<int> a(n + 5), cnt(1005, 0);
    int max_cnt = 0, max_a = 0;
    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        s += a[i];

        if (cnt[a[i]] > max_cnt) {
            max_cnt = cnt[a[i]];
            max_a = a[i];
        }
    }

    if (max_cnt <= 2 || max_cnt <= n / 2 + 1) {
        cout << s << endl;
        return;
    }
    dbg(max_cnt);
    dbg(max_a);

    cout << (s - (max_cnt - (n - max_cnt + 2)) * max_a) << endl;
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
