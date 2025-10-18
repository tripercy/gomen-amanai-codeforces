#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pref(n), suff(n), res(n);
    pref[0] = a[0];
    suff[n - 1] = a[n - 1];
    res[0] = 1;
    res[n - 1] = 1;
    for (int i = 1; i < n; i++) {
        pref[i] = min(a[i], pref[i - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        suff[i] = max(a[i], suff[i + 1]);
    }

    for (int i = 1; i < n - 1; i++) {
        if (a[i] < suff[i] && a[i] > pref[i]) {
            res[i] = 0;
        } else {
            res[i] = 1;
        }
    }

    for (int x : res) {
        cout << x;
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
