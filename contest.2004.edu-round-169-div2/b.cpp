#include <bits/stdc++.h>
#include <utility>

using namespace std;

void solve()
{
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;
    if (la > lb) {
        swap(la, lb);
        swap(ra, rb);
    }
    int m = la == lb;

    if (lb > ra) {
        cout << 1 << endl;
    } else if (lb == ra) {
        cout << 2 << endl;
    } else if (rb >= ra) {
        int n = rb == ra;
        cout << ra - lb + 1 + !n - m << endl;
    } else {
        cout << rb - lb + 2 - m << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}
