#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int cnt1 = 0, cnt0 = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            s[i] == '0' ? cnt0++ : cnt1++;
        }
    }
    int cnta = cnt1, cntb = cnt0;
    char c = '0';
    if (cnt0 > cnt1) {
        swap(cnta, cntb);
        c = '1';
    }
    if (cnta - cntb < 2) {
        cout << cnta + cntb << endl;
        return;
    }
    dbg(cnta);
    dbg(cntb);
    dbg(c);
    dbg(s[0]);
    dbg(s[n - 1]);
    if (cnta == cntb + 2) {
        if (c == s[0] || c == s[n - 1]) {
            cout << (cnta + cntb + 1) << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    if (cnta == cntb + 3) {
        if (c == s[0] && c == s[n - 1]) {
            cout << (cnta + cntb + 2) << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }
    cout << -1 << endl;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    if (MULTITEST) {
        cin >> t;
    }
    while (t--) {
        solve();
    }

    return 0;
}
