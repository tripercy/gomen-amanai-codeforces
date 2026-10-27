#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int last_even = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < min(i + 31, n); j++) {
            int m = a[j] % a[i];
            if (m % 2 == 0) {
                cout << a[i] << " " << a[j] << endl;
                return;
            }
        }
    }
    cout << "-1\n";
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
