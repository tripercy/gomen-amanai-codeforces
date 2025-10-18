#include <iostream>

using namespace std;

int query(int t, int l, int r) {
    cout << t << " " << l << " " << r << "\n";
    cout.flush();
    int s;
    cin >> s;
    return s;
}

void solve() {
    int n;
    cin >> n;
    int k = query(2, 1, n);
    k = k - n * (n + 1) / 2;

    int l = 1, r = n;
    while (r - l + 1 > k) {
        int m = l + (r - l) / 2;
        int k1 = query(1, l, m);
        int k2 = query(2, l, m);
        if (k2 - k1 == k) {
            r = m;
        } else if (k2 == k1) {
            l = m + 1;
        } else {
            int tmp = k2 - k1;
            cout << "! " << m - tmp + 1 << " " << m + (k - tmp) << endl;
            cout.flush();
            return;
        }
    }
    cout << "! " << l << " " << r << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
