#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
#define ll long long
#define tup3 tuple<int, int, int>

using namespace std;
const int MAXN = 2e5 + 5, MAXX = 4e5 + 5;
int n, k;
ll a[MAXN], b[MAXN];

void solve() {
    cin >> n >> k;
    vector<tup3> c(n * 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i - 1] = {a[i], -1, i};
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        c[n + i - 1] = {b[i], 1, i};
    }
    sort(c.begin(), c.end(), [&](tup3 &a, tup3 &b) -> bool {
        int ap = get<0>(a), bp = get<0>(b);
        if (ap == bp) {
            return get<1>(a) > get<1>(b);
        }
        return ap > bp;
    });
    for (int i = 0; i < c.size();) {
        int p = get<0>(c[i]);
        int delta = get<1>(c[i]);
        int j = i + 1;
        while (j < c.size() && get<0>(c[j]) == p) {
            delta += get<1>(c[j]);
            c[j] = {p, 0, get<2>(c[j])};
            j++;
        }
        c[i] = {p, delta, get<2>(c[i])};
        i = j;
    }
    int review = 0;
    ll res = 0;
    unordered_set<int> s;
    for (auto &t : c) {
        int p = get<0>(t), delta = get<1>(t), i = get<2>(t);
        review += delta;
        s.insert(i);
        // cout << p << " " << delta << " " << i << endl;
        if (review <= k) {
            res = max(res, p * (ll)s.size());
        }
    }
    cout << res << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
