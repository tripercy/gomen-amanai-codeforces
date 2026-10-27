#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    cout << *(a.lower_bound(a.size())) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
