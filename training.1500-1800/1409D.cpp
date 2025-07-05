#include <iostream>

#define ll unsigned long long

using namespace std;

int getSum(ll x)
{
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

ll tenPow(int i)
{
    ll res = 1;
    while (i--) {
        res *= 10;
    }
    return res;
}

void solve()
{
    ll n;
    int s;
    cin >> n >> s;

    // cout << n << s << endl;
    ll res = 0;

    while (getSum(n) > s) {
        int i = 0;
        ll tmp = n;
        while (tmp % 10 == 0) {
            tmp /= 10;
            i++;
        }
        ll adding = (10 - tmp % 10) * tenPow(i);
        n += adding;
        res += adding;
    }
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
