#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, j, k;
    cin >> n >> j >> k;

    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m = max(m, a[i]);
    }

    if (k > 1) {
        cout << "YES\n";
        return;
    }

    if (a[j - 1] < m) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
