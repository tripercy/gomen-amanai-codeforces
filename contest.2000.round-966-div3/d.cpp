#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    string s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;

    long long ps[n + 1];
    ps[0] = 0;
    for (int i = 0; i < n; i++) {
        ps[i + 1] = ps[i] + a[i];
    }

    int l = 0;
    int r = n - 1;

    long long res = 0;
    while (l < r) {
        while (l < n && s[l] != 'L')
            l++;
        while (r >= 0 && s[r] != 'R')
            r--;
        if (l >= r)
            break;
        res += ps[r + 1] - ps[l];
        r--;
        l++;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
