#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> coor(n);
    for (int i = 0; i < n; i++) {
        cin >> coor[i].first >> coor[i].second;
    }
    set<pair<int, int>> st;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> p = coor[i];
        if (st.find(p) != st.end()) {
            continue;
        }
        ans += 2;
        if (st.find({p.first + 1, p.second}) != st.end()) {
            ans -= 0.5;
        }
        if (st.find({p.first, p.second + 1}) != st.end()) {
            ans -= 0.5;
        }
        if (st.find({p.first, p.second - 1}) != st.end()) {
            ans -= 0.5;
        }
        if (st.find({p.first - 1, p.second}) != st.end()) {
            ans -= 0.5;
        }
        st.insert(p);
    }
    cout << ans << endl;
}

signed main() {
    solve();
}