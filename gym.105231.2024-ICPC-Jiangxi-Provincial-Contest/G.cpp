#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pii pair<int, int>
const int maxn = 2e5 + 5;
int n, a[maxn], t, m;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            char y;
            cin >> x >> y;
            x %= 5;
            if (y == 'A') {
                ans = (ans + 10 * x) % 5;
            } else {
                ans = (ans + (int)(y - '0') * x) % 5;
            }
        }
        if (ans % 5 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
