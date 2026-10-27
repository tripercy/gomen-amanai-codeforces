#include <bits/stdc++.h>

#define ll long long

using namespace std;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> gte, lte, tmp;
    for (int i = 0; i < n; i++) {
        if (a[i] < l) {
            gte.push_back(a[i]);
        } else if (a[i] > r) {
            lte.push_back(a[i]);
        } else {
            tmp.push_back(a[i]);
        }
    }
    sort(tmp.begin(), tmp.end());
    int i = 0, j = tmp.size() - 1;
    while (i <= j) {
        if (gte.size() < lte.size()) {
            int x = tmp[i++];
            gte.push_back(x);
        } else if (gte.size() > lte.size()) {
            int x = tmp[j--];
            lte.push_back(x);
        } else {
            if (i == j) {
                break;
            }
            int x = tmp[i++];
            int y = tmp[j--];
            gte.push_back(x);
            lte.push_back(y);
        }
    }
    sort(lte.begin(), lte.end());
    sort(gte.begin(), gte.end());
    ll x = l;
    ll y = r;
    if (gte.size() > 0) {
        x = max(x, gte[gte.size() - 1]);
    }
    if (lte.size() > 0) {
        y = min(y, lte[0]);
    }
    ll r1 = 0, r2 = 0;
    for (int v : gte) {
        r1 += x - v;
        r2 += y - v;
    }
    for (int v : lte) {
        r1 += v - x;
        r2 += v - y;
    }
    // cout << x << " " << y << endl;
    cout << min(r1, r2) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
