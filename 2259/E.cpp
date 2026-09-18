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
    vector<int> a(n + 5, 0), pfs(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            pfs[max(1, i - a[i] + 1)]++;
            pfs[min(n + 1, i + a[i])]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        pfs[i] += pfs[i - 1];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << pfs[i] << " ";
    // }
    // cout << "\n";
    vector<int> res(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            if (pfs[i] == 0) {
                res[i] = 1;
            }
            continue;
        }
        int f = 0;
        if (i - a[i] >= 1 && pfs[i - a[i]] == 0) {
            res[i- a[i]] = 1;
            f++;
        }
        if (i + a[i] <= n && pfs[i + a[i]] == 0) {
            res[i + a[i]] = 1;
            f++;
        }
        if (f == 0) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i];
    }
    cout << endl;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    if (MULTITEST) {
        cin >> t;
    }
    int TEST = 1;
    while (t--) {
        dbg(TEST);
        TEST++;
        solve();
    }

    return 0;
}
