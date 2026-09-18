#include <bits/stdc++.h>
#define MULTITEST true
#define MOD 998244353
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

bool chk(string s, int n) {
    for (int i = 2; i < n; i++) {
        if (s[i - 1] + s[i] == s[i] + s[i + 1]) {
            return false;
        }
    }
    return true;
}

void fill_front(string &s, int n, int i) {
    for (; i >= 1; i--) {
        if (s[i] != '?') {
            continue;
        }
        if (s[i + 1] == s[i + 2]) {
            s[i] = ('1' - s[i + 1] + '0');
        } else {
            s[i] = s[i + 1];
        }
    }
}

void fill_back(string &s, int n, int i) {
    dbg(i);
    for (; i <= n; i++) {
        if (s[i] != '?') {
            continue;
        }
        if (s[i - 1] == s[i - 2]) {
            s[i] = ('1' - s[i - 1] + '0');
        } else {
            s[i] = s[i - 1];
        }
    }
}

bool try_fill(string s, int n, int start) {
    for (int i = 1; i <= n; i++) {
        if (s[i] != '?') {
            if (i == 1) {
                s[i + 1] = start + '0';
                fill_back(s, n, 3);
            } else {
                s[i - 1] = start + '0';
                fill_front(s, n, i - 2);
                fill_back(s, n, i + 1);
            }
            break;
        }
    }
    dbg(s);
    return chk(s, n);
}

void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    s = " " + s + " ";

    int cnt = 0, flag = 0, flag2 = 1;
    for (int i = 1; i <= n; i++) {
        if (s[i] != '?') {
            flag = 1;
            cnt++;
            if (cnt == 2) {
                fill_front(s, n, i - 2);
                fill_back(s, n, i + 1);
                cout << chk(s, n) << endl;
                return;
            }
            continue;
        }
        if (s[i - 1] == s[i + 1] && s[i - 1] != '?') {
            cout << "0\n";
            return;
        }
        cnt = 0;
        flag2 = 0;
    }

    if (flag2) {
        cout << (int)chk(s, n) << endl;
        return;
    }

    if (flag) {
        int f1 = try_fill(s, n, 0);
        int f2 = try_fill(s, n, 1);
        dbg(f1);
        dbg(f2);
        cout << (f1 + f2) << endl;
        return;
    }
    cout << "4\n";
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
