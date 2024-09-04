#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n > 2)
        cout << "NO" << endl;
    else {
        if (abs(a[1] - a[0]) == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
