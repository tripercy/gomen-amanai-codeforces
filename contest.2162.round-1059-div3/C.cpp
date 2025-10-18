#include <algorithm>
#include <iostream>
#include <vector>
#define ll long long

using namespace std;
const int MAXP = 35;
ll POW[MAXP];

void solve() {
    int a, b;
    cin >> a >> b;
    int c1 = 0, c2 = 0;
    int x1 = a, x2 = b;
    while (x1 > 1) {
        x1 >>= 1;
        c1++;
    }
    while (x2 > 1) {
        x2 >>= 1;
        c2++;
    }
    if (c2 > c1) {
        cout << -1 << endl;
        return;
    }
    int x = a ^ b;
    if (x <= a) {
        cout << 1 << endl << x << endl;
        return;
    }
    vector<int> res;
    int cnt = 0;
    while (x > 0) {
        if (x & 1) {
            res.push_back(POW[cnt]);
        }
        cnt++;
        x >>= 1;
    }
    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    POW[0] = 1;
    for (int i = 1; i < MAXP; i++) {
        POW[i] = POW[i - 1] * 2;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
