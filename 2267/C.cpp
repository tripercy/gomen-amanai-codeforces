#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

const int MAXN = 3e5 + 5;

int isPrime[MAXN], sz[MAXN];
int divisors[MAXN][80];

void sieve() {
    memset(isPrime, 1, MAXN * sizeof(int));
    memset(sz, 0, MAXN * sizeof(int));
    for (int i = 2; i < MAXN; i++) {
        if (!isPrime[i]) {
            continue;
        }
        divisors[i][sz[i]++] = i;
        for (int j = 2; i * j < MAXN; j++) {
            isPrime[i * j] = 0;
            divisors[i * j][sz[i * j]++] = i;
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    unordered_map<int, ll> sm;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int u : a) {
        for (int i = 0; i < sz[u]; i++) {
            sm[divisors[u][i]] += (ll)u;
        }
    }
    ll res = 0;
    for (int i = 0; i < sz[x]; i++) {
        res = max(res, sm[divisors[x][i]]);
    }
    cout << res << endl;
}

int32_t main() {
    sieve();
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    int TEST = 1;
    if (MULTITEST) {
        dbg(TEST);
        TEST++;
        cin >> t;
    }
    while (t--) {
        solve();
    }

    return 0;
}
