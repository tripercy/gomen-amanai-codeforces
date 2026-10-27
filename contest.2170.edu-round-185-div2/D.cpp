#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    int cnt = 0, tmp = 0, base = 0, blank = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            tmp++;
            blank++;
        } else {
            if (s[i] == 'I') {
                if (i + 1 < n && (s[i + 1] == 'X' || s[i + 1] == 'V')) {
                    base -= 1;
                } else {
                    base += 1;
                }
            } else if (s[i] == 'X') {
                base += 10;
            } else {
                base += 5;
            }
            if (tmp > 0) {
                if (s[i] != 'I') {
                    cnt++;
                    tmp--;
                }
                if (tmp > 0) {
                    cnt2 += tmp / 2;
                }
            }
            tmp = 0;
        }
    }
    if (tmp > 0) {
        cnt += tmp / 2;
    }
    int cx, cv, ci;
    // cout << cnt << " " << cnt2 << endl;
    while (q--) {
        cin >> cx >> cv >> ci;
        int res = base;
        int left = blank;
        res -= min(ci, cnt);
        left -= min(ci, cnt);
        res += max(ci - cnt, 0ll);
        left -= max(ci - cnt, 0ll);
        if (left > 0) {
            ci = max(ci - cnt, 0ll);
            res -= min(ci, cnt2) * 2;
        }
        res += min(left, cv) * 5;
        left = max(0ll, left - cv);
        res += min(left, cx) * 10;
        cout << res << endl;
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
