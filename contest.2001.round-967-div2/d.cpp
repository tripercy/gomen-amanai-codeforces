#include <bits/stdc++.h>

using namespace std;

bool cmp(int i, int j) {
    return i < j;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<int, vector<int>> mp;

    vector<int> keys;
    for (int i = 0; i < n; i++) {
        if (mp.find(a[i]) == mp.end()) {
            keys.push_back(a[i]);
            mp[a[i]] = vector<int>();
        }
        mp[a[i]].push_back(i);
    }

    vector<int> res (keys.size(), -1);
    for (int i = 0; i < keys.size(); i++) {

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
