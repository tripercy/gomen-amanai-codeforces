#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll sumRange(ll a, ll b)
{
    // if (a > b)
    //     swap(a, b);
    return (b - a + 1) * (a + b) / 2;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll l = k, r = k + n - 1;
        while (l < r) {
            ll m = (l + r) / 2;
            ll s = abs(sumRange(k, m) - sumRange(m + 1, k + n - 1));
            ll s2 = abs(sumRange(k, m - 1) - sumRange(m, k + n - 1));
            ll s3 = abs(sumRange(k, m + 1) - sumRange(m + 2, k + n - 1));
            if (s < s2 && s < s3) {
                break;
            }
            if (s < s2) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        ll m = (l + r) / 2;
        ll res = abs(sumRange(k, m) - sumRange(m + 1, k + n - 1));
        cout << res << endl;
    }
}
