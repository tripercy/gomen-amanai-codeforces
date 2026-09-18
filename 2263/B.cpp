#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> res (n, vector<int> (n, - 1));
    if (k < n || k == 2 * n) {
        cout << "-1\n";
        return;
    }
    int folds = k - n;
    int x = k;
    for (int i = n - 1; i >= 0; i--) {
        res[i][i] = x--;
        if (folds) {
            folds--;
            res[i][i - 1] = x--;
        }
    }

    x = k + 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (res[i][j] == -1) {
                res[i][j] = x++;
            }
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}

int32_t main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    int TEST = 1;
    if (MULTITEST) {
        dbg(TEST);
        TEST++;
        cin >> t;
    }
    while (t--) {
        solve();
    }

    return 0;
}
