#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int n, m, k;

int search(int i, int j)
{
    int c1 = j + k - i;
    int c2 = 1 + n - k;
    int c3 = 1 + k;

    int res = min(c1, min(c2, c3));

    return res;
}

void solve()
{
    cin >> n >> m >> k;

    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mp[s] = i;
    }

    vector<bool> stage(n, false);
    int sa = 0, sb = 0;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        stage[mp[s]] = true;
        sb++;
    }

    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        if (stage[mp[s]]) {
            sa++;
            sb--;
        }
    }

    cout << search(sa, sb) << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
