#include <bits/stdc++.h>

using namespace std;

char ch[3] = {'<', '*', '>'};

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int c1, c2, c3, last;
    c1 = c2 = c3 = last = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '<') {
            if (flag) {
                cout << -1 << endl;
                return;
            }
            c1++;
        } else if (!flag) {
            last = i;
            flag = true;
        }
    }
    flag = false;
    for (int i = last; i < n; i++) {
        if (s[i] == '*') {
            if (flag) {
                cout << -1 << endl;
                return;
            }
            c2++;
        } else if (!flag) {
            last = i;
            flag = true;
        }
    }
    flag = false;
    for (int i = last; i < n; i++) {
        if (s[i] == '>') {
            if (flag) {
                cout << -1 << endl;
                return;
            }
            c3++;
        } else if (!flag) {
            last = i;
            flag = true;
        }
    }
    if (c2 > 1) {
        cout << -1 << endl;
        return;
    }
    cout << max(c1, c3) + c2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
