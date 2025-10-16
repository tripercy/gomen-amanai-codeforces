#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN];
int n, k;

void solve() {
    cin >> n >> k;
    unordered_map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int res = mp[k];
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt += (mp.find(i) == mp.end());
    }
    res += max(0, cnt - res);
    cout << res << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
