#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

#define int long long
// #define ll long long
using pii = pair<int, int>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 5);
    vector<vector<int>> a(n + 5, vector<int>(m + 5));
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    int res = m;
    int sum = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            sum += a[i][j];
            pq.push(a[i][j]);
        }
        if (sum > v[i]) {
            while (sum - pq.top() >= v[i]) {
                sum -= pq.top();
                pq.pop();
            }
            res = min(res, (int)pq.size());
        }
    }
    cout << res << endl;
}

int32_t main() {
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
