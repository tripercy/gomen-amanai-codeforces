#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 1; i < m; i++) {
        if (b[i] == 1) {
            cout << 1 << endl;
            return;
        }
    }
    cout << (n - b[m - 1] + 1) << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
