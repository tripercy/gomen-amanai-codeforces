#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const string p[] { "BR", "BG", "BY", "GR", "GY", "RY" };

bool canGo(string from, string to)
{
    return from[0] == to[0] || from[0] == to[1] || from[1] == to[0] || from[1] == to[1];
}

void solve()
{
    int n, q;
    cin >> n >> q;
    unordered_map<string, vector<int>> mp;
    string c[n];

    for (int i = 0; i < 6; i++) {
        mp[p[i]] = vector<int>(n, -1);
    }

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < 6; j++) {
            if (i > 0) {
                mp[p[j]][i] = mp[p[j]][i - 1];
            }
        }
        mp[c[i]][i] = i;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < 6; j++) {
            if (mp[p[j]][i + 1] != -1 && abs(mp[p[j]][i] - j) > abs(mp[p[j]][i + 1] - j)) {
                mp[p[j]][i] = mp[p[j]][i + 1];
            }
        }
    }

    while (q--) {
        int from, to;
        cin >> from >> to;
        from--;
        to--;
        if (from > to) {
            swap(from, to);
        }
        if (canGo(c[from], c[to])) {
            cout << abs(from - to) << endl;
            continue;
        }
        int res = INT_MAX;
        for (int i = 0; i < 6; i++) {
            string bridge = p[i];
            if (c[from] != bridge && canGo(c[from], bridge)) {
                int b1i = mp[bridge][from];
                int b2i = mp[bridge][to];
                if (b1i == -1)
                    continue;
                int d1 = abs(from - b1i) + abs(to - b1i);
                int d2 = abs(from - b2i) + abs(to - b2i);
                res = min(res, min(d1, d2));
            }
        }
        if (res == INT_MAX)
            res = -1;
        cout << res << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
