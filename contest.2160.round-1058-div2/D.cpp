#include <bits/stdc++.h>
#include <cstdio>

using namespace std;

const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN], c[MAXN];

int query(int known[MAXN], int n, int i) {
    cout << "? " << n + 1 << " ";
    for (int i = 1; i <= n; i++) {
        cout << known[i] << " ";
    }
    cout << i << endl;
    fflush(stdout);
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n, x;
    cin >> n;

    int cntB = 1, cntC = 0;
    b[1] = 1;
    for (int i = 2; i <= 2 * n; i++) {
        int x = query(b, cntB, i);
        if (x != 0) {
            a[i] = x;
            c[++cntC] = i;
        } else {
            b[++cntB] = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        int x = query(c, n, b[i]);
        a[b[i]] = x;
    }

    cout << "!";
    for (int i = 1; i <= 2 * n; i++) {
        cout << " " << a[i];
    }
    cout << endl;
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
