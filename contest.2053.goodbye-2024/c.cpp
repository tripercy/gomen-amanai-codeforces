#include <iostream>

#define int long long

using namespace std;

int cnt, res;

void solve(int n, int k)
{
    if (n < k) {
        return;
    }
    int m = (n + 1) / 2;
    solve(n / 2, k);
    res = res * 2 + m * cnt;
    cnt *= 2;
    if (n % 2 == 1) {
        res += m;
        cnt += 1;
    }
    // cout << n << " " << res << " " << cnt << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cnt = 0;
        res = 0;
        solve(n, k);
        cout << res << endl;
    }
}
