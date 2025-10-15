#include <bits/stdc++.h>

using namespace std;
const int MAXN = 5005;
int a[MAXN], steps[MAXN];

void dump_steps(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << "\t";
    }
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << steps[i] << "\t";
    }
    cout << endl;
}

void solve() {
    for (int i = 1; i <= MAXN; i++) {
        steps[i] = MAXN;
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(&a[1], &a[n + 1]);
    int x = a[1];
    for (int i = 1; i <= n; i++) {
        x = gcd(x, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j < a[i]; j++) {
            int k = gcd(a[i], j);
            steps[k] = min(steps[k], steps[j] + 1);
        }
        steps[a[i]] = 0;
    }
    // dump_steps(30);
    int res = steps[x];
    if (steps[x] > 0) {
        a[1] = x;
    }
    for (int i = 1; i <= n; i++) {
        res += (a[i] != x);
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
