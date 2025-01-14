#include <cstdint>
#include <iostream>
#include <vector>

#define int long long

using namespace std;

const int NMAX = 1e5 + 5;

int32_t main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(NMAX, 0), dp(NMAX);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    dp[0] = 0;
    dp[1] = cnt[1];

    for (int i = 2; i < NMAX; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
    }
    cout << dp[NMAX - 1] << '\n';
}
