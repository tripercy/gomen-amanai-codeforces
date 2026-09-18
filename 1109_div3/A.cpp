#include<bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int res = 0;
    int curr = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '*') {
            curr = 0;
        } else {
            curr++;
            res = max(res, curr);
        }
    }
    cout << (res + 1) / 2 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
