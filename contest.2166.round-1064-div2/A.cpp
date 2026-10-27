#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        cnt += (s[i] != s[n - 1]);
    }
    cout << cnt << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
