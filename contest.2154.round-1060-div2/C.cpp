#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>

using namespace std;
const int MAXN = 2e5 + 5;
int n;
ll a[MAXN], b[MAXN], cnt[MAXN];
pii c[MAXN];
bool isPrime[MAXN];
vector<int> facts[MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        c[i] = {b[i], a[i]};
    }
    sort(&c[1], &c[n + 1]);
    ll res = (c[1].second % 2) * c[1].first + (c[2].second % 2) * c[2].first;
    memset(cnt, 0, sizeof(cnt));
    unordered_set<ll> s;
    for (int i = 1; i <= n; i++) {
        for (int f : facts[c[i].second]) {
            if (cnt[f] == 1) {
                cout << 0 << endl;
                return;
            }
            cnt[f]++;
            if (i > 1) {
                s.insert(f);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int f : facts[c[i].second]) {
            cnt[f]--;
        }
        for (int f : facts[c[i].second + 1]) {
            if (cnt[f] == 1) {
                res = min(c[i].first, res);
            }
        }
        for (int f : facts[c[i].second]) {
            cnt[f]++;
        }
    }
    for (ll f : s) {
        ll tmp = f * (c[1].second / f + 1) - c[1].second;
        tmp *= c[1].first;
        res = min(res, tmp);
    }
    cout << res << endl;
}

int main(int argc, char *argv[]) {
    memset(isPrime, 1, sizeof(isPrime));
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i < MAXN; i++) {
        if (!isPrime[i]) {
            continue;
        }
        for (int j = 1; i * j < MAXN; j++) {
            isPrime[i * j] = false;
            facts[i * j].push_back(i);
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
