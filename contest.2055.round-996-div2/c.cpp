#include <iostream>
#include <vector>

using namespace std;

#define int long long

void solve()
{
    int n, m;
    string s;
    cin >> n >> m >> s;
    s += s[s.length() - 1];
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> sr(n, 0), sc(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sr[i] += a[i][j];
        }
        // cout << sr[i] << endl;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sc[i] += a[j][i];
        }
        // cout << sc[i] << endl;
    }

    int r = 0, c = 0;
    for (char d : s) {
        if (d == 'D') {
            int x = sr[r];
            sc[c] -= x;
            a[r][c] = -x;
            r++;
        } else {
            int x = sc[c];
            sr[r] -= x;
            a[r][c] = -x;
            c++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
