#include<bits/stdc++.h>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a (n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long left = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < i + 1) {
            if (left < i + 1 - a[i]) {
                cout << "NO\n";
                return;
            } else {
                left -= i + 1 - a[i];
            }
        } else {
            left += a[i] - i - 1;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
