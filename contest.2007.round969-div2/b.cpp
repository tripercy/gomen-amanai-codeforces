#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    long long x = 0;
    for (int i = 0; i < n; i++) {
        long long tmp;
        cin >> tmp;
        x = max(x, tmp);
    }

    while (m--) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (x >= l && x <= r) {
            x += c == '+' ? 1 : -1;
        }
        cout << x;
        if (m > 0)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
