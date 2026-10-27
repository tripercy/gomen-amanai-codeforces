#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int mx = 0, st = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > mx) {
            mx = a[i];
            st = i;
        }
    }
    stack<int> s;
    s.push(mx);
    ll res = 0;
    for (int i = 1; i < n; i++) {
        int j = (st + i) % n;
        if (s.top() <= a[j]) {
            while (!s.empty() && s.top() <= a[j]) {
                s.pop();
                int tmp = a[j];
                if (!s.empty() && s.top() < tmp) {
                    tmp = s.top();
                }
                res += tmp;
            }
        }
        s.push(a[j]);
    }
    s.pop();
    while (!s.empty()) {
        res += s.top();
        s.pop();
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
