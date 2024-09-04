#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n / 2; i++)
            cout << i + 1 << " ";

        cout << n;

        for (int i = 0; i < n / 2; i++) {
            cout << " " << n - i - 1;
            // 1 2 5 4 3
        }
        cout << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
