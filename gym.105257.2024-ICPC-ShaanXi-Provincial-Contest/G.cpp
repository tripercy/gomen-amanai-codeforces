#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
const int maxn = 2e5 + 5;
int n, t, m;
string s;
int dp[20][2];
int cal(int pos, bool check, int x) {
    if (pos == n + 1) {
        return 1;
    }
    if (dp[pos][check] != -1) return dp[pos][check];
    int &res = dp[pos][check];
    res = 0;
    int lim = check ? 9 : (s[pos] - '0' - 0);
    for (int i = 0; i <= lim; i++) {
        if (i == x) continue;
        res += cal(pos + 1, check | (i < lim), x);
    }
    return res;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        int x;
        cin >> s >> x;
        n = s.size();
        s = " " + s;
        memset(dp, 255, sizeof(dp));
        cout << cal(1, 0, x) << "\n";
    }
    return 0;
}
