#include <bits/stdc++.h>
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
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> printed(n + 5, 0);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            st.push(i);
        } else if (s[i] == '2') {
            int x = i;
            if (!st.empty()) {
                x = st.top();
                st.pop();
            }
            printed[x] = 1;
        } else {
            printed[i] = 1;
        }
    }
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        if (!printed[i]) {
            res.push_back(i);
        }
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
