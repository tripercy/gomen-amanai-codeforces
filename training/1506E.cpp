#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#define dump(a)                                                                \
    do {                                                                       \
        cout << "[DBG] " << #a << ": ";                                        \
        for (auto &x : a)                                                      \
            cout << x << " ";                                                  \
        cout << endl;                                                          \
    } while (0)
#else
#define dbg(x)
#define dump(a)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n;
    cin >> n;
    vector<int> q(n), a(n, -1), b(n, -1), visl(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }
    int curr = 0, l = 1;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (q[i] != curr) {
            a[i] = q[i];
            b[i] = q[i];
            for (int j = curr + 1; j < q[i]; j++)
                st.push(j);
            curr = q[i];
            visl[q[i]] = 1;
        } else {
            while (visl[l])
                l++;
            a[i] = l++;
            b[i] = st.top();
            st.pop();
        }
    }
    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";
    for (int x : b) {
        cout << x << " ";
    }
    cout << "\n";
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
