#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), pfs(n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pfs[i + 1] = pfs[i] ^ a[i];
        }
        bool flag = true;
        vector<vector<int>> mark(31);
        int i;
        for (i = 30; i >= 0 && flag; i--) {
            if (((x >> i) & 1) == 1) {
                bool full0 = true;
                for (int j = 0; j < a.size(); j++) {
                    if (((a[j] >> i) & 1) == 1) {
                        full0 = false;
                        break;
                    }
                }
                if (full0) {
                    break;
                }
                mark[i] = a;
                continue;
            }
            vector<int> tmp;
            for (int j = 0; j < a.size(); j++) {
                if (((a[j] >> i) & 1) == 0) {
                    tmp.push_back(a[j]);
                } else {
                    int m = a[j];
                    j++;
                    while (j < n && ((a[j] >> i) & 1) == 0) {
                        m ^= a[j];
                        j++;
                    }
                    if (j == a.size()) {
                        flag = false;
                        break;
                    }
                    tmp.push_back(m);
                }
                // for (auto x : tmp) {
                //     cout << x << " ";
                // }
                // cout << endl;
            }
            a = tmp;
        }
        if (!flag) {
            cout << -1 << endl;
        } else {
            cout << a.size() << endl;
        }
    }
}
