#include <bits/stdc++.h>
#include <functional>
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

void solve() {
    int n;
    cin >> n;
    vector<int> even, odd;
    int mx = -1;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        i % 2? odd.push_back(x) : even.push_back(x);
    }
    sort(even.begin(), even.end(), greater<int>());
    sort(odd.begin(), odd.end(), greater<int>());
    vector<int> a = even, b = odd;
    if (a[0] < b[0]) {
        a = odd;
        b = even;
    }
    vector<int> l, r;
    l.push_back(a[0]);
    r.push_back(a[0]);
    for (int i = 1; i < a.size(); i++) {
        l.push_back(a[i]);
    }
    for (int i = 2; i < a.size(); i++) {
        r.push_back(a[i]);
    }
    int li = 0, ri = 0;
    for (int i = 0; i < l.size(); i++) {
        cout << l[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++) {
        int x = b[i];
        int flag = false;
        if (li < l.size() - 1 && x < l[li] && x > l[li + 1]) {
            li++;
            continue;
        }
        if (ri < r.size() - 1 && x < r[ri] && x > r[ri + 1]) {
            li++;
            continue;
        }

        if (!flag) {
            cout << x << " " << li << " " << ri;
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
