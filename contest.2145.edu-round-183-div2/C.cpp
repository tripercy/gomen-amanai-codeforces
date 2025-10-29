#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n + 1, 0);
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += (s[i] == 'a' ? 1 : -1);
        a[i + 1] = curr;
    }
    if (curr == 0) {
        cout << 0 << endl;
        return;
    }
    unordered_map<int, int> mp;
    mp[0] = 0;
    int res = INT_MAX;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        int j = x - curr;
        if (mp.find(j) != mp.end()) {
            // cout << i << " " << j << " " << mp[j] << endl;
            res = min(res, i - mp[j]);
        }
        mp[x] = i;
    }
    cout << (res >= n ? -1 : res) << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
