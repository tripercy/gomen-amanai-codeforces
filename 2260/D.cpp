/**
 *    author:  thabumi
 *    created: 08-09-2026 21:34:08
 *    note:
**/

#include <bits/stdc++.h>

#define MULTI_TEST

using namespace std;

void run_case() {
    int n;
    string s;
    cin >> n >> s;
    if (s[0] == '0') {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '0' && s[i + 1] == '0') {
            cout << -1 << '\n';
            return;
        }
    }
    bool good = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '+' && s[i + 1] == '-') {
            good = false;
            break;
        }
        if (s[i] == '-' && s[i + 1] == '+') {
            good = false;
            break;
        }
    }
    for (int i = 0; i < n; i += 2) {
        if (s[i] == '0') {
            good = false;
            break;
        }
    }
    if (good) {
        cout << 1 << '\n';
        return;
    }
    good = true;
    for (int i = 0; i < n - 3; i++) {
        if (s[i] == '-' && s[i + 1] == '+' && s[i + 2] == '+' && s[i + 3] == '-') {
            good = false;
            break;
        }
        if (s[i] == '+' && s[i + 1] == '-' && s[i + 2] == '-' && s[i + 3] == '+') {
            good = false;
            break;
        }
    }
    if (good) {
        cout << 2 << '\n';
        return;
    }
    cout << 3 << '\n';
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    t = 1;
#ifdef MULTI_TEST
    cin >> t;
#endif
    for (int i = 1; i <= t; i++) {
    //    cout << "Case #" << i << ": ";
        run_case();
    }
    return 0;
}
