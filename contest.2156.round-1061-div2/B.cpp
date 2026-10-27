#include <iostream>

using namespace std;

void solve() {
    int n, q;
    string s;
    cin >> n >> q;
    cin >> s;

    int cntb = 0;
    for (char c : s) {
        cntb += (c == 'B');
    }
    while (q--) {
        int x;
        cin >> x;
        int res = 0;
        if (cntb == 0) {
            res += x / n + x % n;
        } else {
            int i = 0;
            while (x > 0) {
                if (s[i] == 'B') {
                    x /= 2;
                } else {
                    x--;
                }
                i = (i + 1) % n;
                res++;
            }
        }
        cout << res << endl;
    }
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
