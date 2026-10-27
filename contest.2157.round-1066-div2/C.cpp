#include <bits/stdc++.h>

#define pii pair<int, int>

using namespace std;

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<pii> q1, q2;
    for (int i = 0; i < q; i++) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) {
            q1.push_back({l, r});
        } else {
            q2.push_back({l, r});
        }
    }

    vector<int> ans(n + 1, k);
    vector<bool> marked(n + 1, false);
    for (auto &p : q1) {
        for (int i = p.first; i <= p.second; i++) {
            marked[i] = true;
        }
    }
    sort(q2.begin(), q2.end());
    for (auto &p : q2) {
        int curr = 0;
        for (int i = p.first; i <= p.second; i++) {
            if (ans[i] > k) {
                continue;
            }
            if (ans[i] < k) {
                curr = (ans[i] + 1) % k;
                continue;
            }
            if (marked[i]) {
                ans[i] = k + 1;
            } else {
                ans[i] = curr;
                curr = (curr + 1) % k;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
