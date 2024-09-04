#include <bits/stdc++.h>
#include <functional>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    for (int i = 1; i < n && k > 0; i += 2) {
        int m = min(k, a[i - 1] - a[i]);
        a[i] += m;
        k -= m;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += (i % 2 ? -1 : 1) * a[i];
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
