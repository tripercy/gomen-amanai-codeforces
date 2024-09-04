#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

void check(int a[], string& s, int n)
{
    unordered_map<char, int> mp;
    unordered_map<int, char> mp2;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (mp.find(c) == mp.end()) {
            mp[c] = a[i];
        } else {
            if (mp[c] != a[i]) {
                cout << "NO" << endl;
                return;
            }
        }

        if (mp2.find(a[i]) == mp2.end()) {
            mp2[a[i]] = c;
        } else if (mp2[a[i]] != c) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO" << endl;
            continue;
        }
        check(a, s, n);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
