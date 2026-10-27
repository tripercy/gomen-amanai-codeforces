#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
    }
    int res = 0;
    for (auto &p : mp) {
        if (p.first < p.second) {
            res += p.second - p.first;
        } else if (p.first > p.second) {
            res += p.second;
        }
    }
    cout << res << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
