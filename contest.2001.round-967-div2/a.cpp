#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin>>n;
    unordered_map<int, int> mp;

    int res = n - 1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
        res = min(res, n - mp[x]);
    }

    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
