#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> res(n, vector<char>(m, '1'));

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {

            if (i % 2) {
                if (j % 2) {
                    res[i][j] = '*';
                }
            } else {
                if (!(j % 2)) {
                    res[i][j] = '*';
                }
            }
        }
    }

    if (m % 2 && n % 2) {
        int left = max(m, n) / 2;
        int x = min(m, n);
        int i = 2;
        for (; i < x - 1; i += 2) {
            res[i][i] = '+';
        }
        i -= 2;

        for (int j = i + 2; j < max(m, n) - 1; j+= 2) {
            if (n > m) res[j][i] = '+';
            else res[i][j] = '+';
        }
    }

    if (m % 2 && n % 2 == 0) {
        for (int i = 2; i < n - 1; i += 2) {
            res[i][2] = '+';
        }
    }

    if (m % 2 == 0 && n % 2) {
        for (int i = 2; i < m - 1; i += 2) {
            res[2][i] = '+';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
}

int main()
{
    solve();
}
