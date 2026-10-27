#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;
const int MAXN = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m), c(m);
    vector<int> dp[MAXN];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
    }
    vector<pii> v(m);
    for (int i = 0; i < n; i++) {
        v[i] = {b[i], c[i]};
    }
    sort(v.begin(), v.end(), [&](pii &a, pii &b) -> bool {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
