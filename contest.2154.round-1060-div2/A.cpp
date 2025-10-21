#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int res = 0;
    int i = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            continue;
        }
        bool flag = false;
        for (int j = max(0, i - k + 1); j < i; j++) {
            if (s[j] == '1') {
                flag = true;
                break;
            }
        }
        if (!flag) {
            res++;
        }
    }
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
