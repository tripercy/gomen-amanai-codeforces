#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e5 + 5;
string s;
int n;

int cal(char c) {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (s[i] == c) {
            v.push_back(i);
        }
    }
    if (v.size() == 0) {
        return 0;
    }
    for (int i = 0; i < v.size(); i++) {
        v[i] -= i + 1;
    }
    sort(v.begin(), v.end());
    int m = v.size();
    int med = v[(m - 1) / 2];
    int res = 0;
    for (int i = 0; i < v.size(); i++) {
        res += abs(v[i] - med);
    }
    return res;
}

void solve() {
    cin >> n;
    cin >> s;
    s = " " + s;
    cout << min(cal('a'), cal('b')) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
