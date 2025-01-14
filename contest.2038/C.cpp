// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>

const int maxn = 2e5 + 5;
int n, a[maxn], t, m, b[maxn], k, c[maxn];

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            b.push_back(a[i]);
            i++;
        }
    }
    if (b.size() < 4) {
        cout << "NO\n";
        return;
    }

    int x1 = b[0], x2 = b[b.size() - 2], y1 = b[1], y2 = b[b.size() - 1];
    cout << "YES\n";
    cout << x1 << " " << y1 << " " << x1 << " " << y2 << " " << x2 << " " << y1 << " " << x2 << " " << y2 << "\n";
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
