#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    unordered_set<int> su[n + 1], sv[n + 1];
    for (int i = 0; i < m; i++) {
        int iu, iv;
        cin >> iu >> iv;
        su[iu].insert(iv);
        sv[iv].insert(iu);
    }

    int res = 0;
    int cv = 0;
    for (int i = 1; i <= n; i++) {
        if (sv[i].size() == 0) {
            cv++;
        } else if (sv[i].size() == 1) {
            int iu = *sv[i].begin();
            if (su[iu].size() > 1) {
                cv++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (su[i].size() == 0) {
            res += cv;
        } else if (su[i].size() == 1) {
            int iv = *su[i].begin();
            if (sv[iv].size() > 1) {
                res += cv;
            }
        }
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
