#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

int calc(int a, int b, int k) {
    int z = abs(a - b);
    return min(z, k - z);
}

signed main() {
    int k, n;
    cin >> k >> n;
    vector<set<int>> st(n + 1), dist(n + 1);
    vector<int> a(2 * n + 1);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for (int i = n; i < 2 * n; i++) a[i] = a[i - n];
    for (int i = 0, j = 0; i < n; i++) {
        while (calc(a[i], a[j], k) < calc(a[i], a[j + 1], k)) {
            j++;
        }
        st[i].insert(j % n);
        st[j % n].insert(i);
        dist[i].insert(j % n);
        if (calc(a[i], a[j], k) == calc(a[i], a[j + 1], k)) {
            st[i].insert((j + 1) % n);
            st[(j + 1) % n].insert(i);
            dist[i].insert((j + 1) % n);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, (long long)st[i].size());

    for (int i = 0; i < n; i++)
        if (dist[i].size() == 2) {
            int x = *dist[i].begin();
            int y = *dist[i].rbegin();
            if (dist[x].count(y) || dist[y].count(x)) ans = max(ans, 3ll);
        }

    cout << ans << endl;
}
