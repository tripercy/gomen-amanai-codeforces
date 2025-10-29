#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    if (n == k) {
        string res(n, '-');
        cout << res << endl;
        return;
    }
    vector<char> res(n + 2, '+');
    res[0] = res[n + 1] = '-';
    int l1 = 1, l2 = 1, r1 = n, r2 = n;

    for (char c : s) {
        if (c == '0') {
            res[l1] = '?';
            res[l2] = '-';
            l1++;
            l2++;
        } else if (c == '1') {
            res[r1] = '?';
            res[r2] = '-';
            r1--;
            r2--;
        } else {
            res[r1] = '?';
            res[l1] = '?';
            l1++;
            r1--;
        }
    }
    if (res[r1] == '-' || res[l1] == '-') {
        res = vector<char>(n + 2, '-');
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i];
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
