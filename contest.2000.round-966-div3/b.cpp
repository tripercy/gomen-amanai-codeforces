#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<bool> b (n + 1, false);
        b[a[0]] = true;

        bool flag = true;
        for (int i = 1; i < n; i++) {
            bool left = a[i] - 1 > 0 && b[a[i] - 1];
            bool right = a[i] + 1 <= n && b[a[i] + 1];
            // cout << a[i] << " " << left << " " << right << endl;
            flag = left || right;
            if (!flag)
                break;
            b[a[i]] = true;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}
