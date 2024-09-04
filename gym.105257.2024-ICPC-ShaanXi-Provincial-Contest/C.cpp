#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), deg(2 * n + 1), f(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        deg[a[i]]++;
    }
    queue<int> q;
    for (int i = 1; i <= 2 * n; i++) {
        if (!deg[i]) q.push(i);
    }
    int ans = 2 * n;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        ans--;
        if (cur > n) {
            ans += f[cur];
            continue;
        }
        f[a[cur]] = max(f[a[cur]], f[cur] + 1);
        if (--deg[a[cur]] == 0) q.push(a[cur]);
    }
    cout << ans << endl;
}

signed main() {
    solve();
}
