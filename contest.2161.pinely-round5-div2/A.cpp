#include <iostream>

using namespace std;

void solve() {
    int r0, x, d, n;
    string rounds;
    cin >> r0 >> x >> d >> n;
    cin >> rounds;
    int res = 0;
    for (char r : rounds) {
        if (r == '1' || r0 < x) {
            r0 = max(0, r0 - d);
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
