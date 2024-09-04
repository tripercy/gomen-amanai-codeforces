#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0);
    cout << (sum != s ? n - 1 : n) << endl;
}

signed main() {
    solve();
}