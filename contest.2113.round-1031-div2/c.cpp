#include <bits/stdc++.h>
#include <climits>
#include <cstdlib>

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> mine(n);
    for (int i = 0; i < n; i++) {
        cin >> mine[i];
    }
    vector<vector<int>> pref(n, vector<int>(m, 0));
    int res = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mine[i][j] == 'g') {
                pref[i][j] = 1;
                res++;
            }
        }
    }
    for (int i = 1; i < m; i++) {
        pref[0][i] += pref[0][i - 1];
    }
    for (int i = 1; i < n; i++) {
        pref[i][0] += pref[i - 1][0];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            pref[i][j] += pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    int lost = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mine[i][j] == '.') {
                int r1 = min(n - 1, i + k - 1);
                int c1 = min(m - 1, j + k - 1);
                int r2 = max(0, i - k + 1) - 1;
                int c2 = max(0, j - k + 1) - 1;
                int tmp = pref[r1][c1];
                if (r2 >= 0) {
                    tmp -= pref[r2][c1];
                }
                if (c2 >= 0) {
                    tmp -= pref[r1][c2];
                }
                if (r2 >= 0 && c2 >= 0) {
                    tmp += pref[r2][c2];
                }
                // cout << i << " " << j << " " << r1 << " " << c1 << " " << r2
                //      << " " << c2 << " " << tmp << endl;
                lost = min(lost, tmp);
            }
        }
    }
    cout << res - lost << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
