#include <bits/stdc++.h>
#define MULTITEST false
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int sum, limit;
    cin >> sum >> limit;

    vector<pii> v;
    for (int i = 1; i <= limit; i++) {
        int x = i;
        int lb = 1;
        while (x % 2 == 0) {
            x /= 2;
            lb *= 2;
        }
        v.push_back({lb, i});
    }
    sort(v.begin(), v.end(), [](pii &a, pii &b) { return a.first > b.first; });
    int s = 0;
    vector<int> res;
    for (auto &p : v) {
        // cout << p.first << " " << p.second << endl;
        if (s == sum) {
            break;
        }
        if (s + p.first > sum) {
            continue;
        }
        res.push_back(p.second);
        s += p.first;
    }
    if (s < sum) {
        cout << "-1\n";
        return;
    }
    cout << res.size() << endl;
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int32_t main() {
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
