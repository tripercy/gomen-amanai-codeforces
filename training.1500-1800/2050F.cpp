#include <cstdlib>
#include <iostream>
#include <numeric>

#define NMAX (int)2e5 + 5
#define LGMAX 18
int a[NMAX], lg[NMAX];
int st[LGMAX][NMAX];

using namespace std;

void precalLg()
{
    lg[1] = 0;
    for (int i = 2; i < NMAX; i++) {
        lg[i] = lg[i / 2] + 1;
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++) {
        st[0][i] = abs(a[i] - a[i + 1]);
    }

    for (int j = 1; j < LGMAX; j++) {
        for (int i = 0; i + (1 << j) - 1 < n - 1; i++) {
            st[j][i] = gcd(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "0 ";
            continue;
        }
        int k = lg[r - l];
        l--;
        r -= 2;
        // cout << k << " " << l << " " << r << endl;
        cout << gcd(st[k][l], st[k][r - (1 << k) + 1]) << " ";
    }
    cout << endl;
}

int main()
{
    precalLg();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
