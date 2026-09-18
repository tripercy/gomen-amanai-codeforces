#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

long long power_two_mod(long long x, long long m) {
    if (m == 1) return 0;
    long long base = 2 % m;
    long long result = 1;
    
    while (x > 0) {
        if (x & 1) {
            result = (__int128)result * base % m;
        }
        base = (__int128)base * base % m;
        x >>= 1;
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 5, 0), pfs(n + 5, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            pfs[max(1, i - a[i] + 1)]++;
            pfs[min(n + 1, i + a[i])]--;
        }
    }
    for (int i = 1; i <= n; i++) {
        pfs[i] += pfs[i - 1];
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << pfs[i] << " ";
    // }
    // cout << "\n";
    int cnt = 0, f = 0;
    for (int i = 1; i <= n; i++) {
        cnt += a[i] == -1 && pfs[i] == 0;
        f |= a[i] == 0;
        int f = 0;
        if (i - a[i] >= 1 && pfs[i - a[i]] == 0) {
            f++;
        }
        if (i + a[i] <= n && pfs[i + a[i]] == 0) {
            f++;
        }
        if (f == 0) {
            cout << "0\n";
            return;
        }
    }
    cout << power_two_mod(cnt, 1e9 + 7) - 1 + f << endl;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    if (MULTITEST) {
        cin >> t;
    }
    int TEST = 1;
    while (t--) {
        dbg(TEST);
        TEST++;
        solve();
    }

    return 0;
}
