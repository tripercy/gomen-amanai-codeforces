#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n, k, l;
    cin >> n >> k >> l;
    k <<= 1;
    l <<= 1;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
        pos[i] <<= 1;
    }

    int res = 0;
    if (pos[0] != 0) {
        int t = pos[0];
        res += t;
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            if (pos[i] < pos[i - 1] + k) {
                pos[i] = min(pos[i] + t, pos[i - 1] + k);
            } else if (pos[i] > pos[i - 1] + k) {
                pos[i] = max(pos[i] - t, pos[i - 1] + k);
            }
        }
    }

    int i = 0, p = 0, t = 0;
    do {
        while (pos[i] + k > p) {
            p = pos[i] + k;
        }
        // cout << i << " " << p << endl;
        t++;
        pos[i]++;
    } while (i < n - 1 && p < l);
    res += t - 1;
    res += max(0, l - p);
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
