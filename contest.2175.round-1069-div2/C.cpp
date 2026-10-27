#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    map<char, int> cnt, ms;
    for (char c : s) {
        ms[c]++;
    }
    for (char c : t) {
        if (ms[c] > 0) {
            ms[c]--;
        } else {
            cnt[c]++;
        }
    }
    for (auto p : ms) {
        if (p.second != 0) {
            cout << "Impossible\n";
            return;
        }
    }
    int i = 0;
    for (auto p : cnt) {
        while (i < s.size() && p.first >= s[i]) {
            cout << s[i];
            i++;
        }
        while (p.second--) {
            cout << p.first;
        }
    }
    for (; i < s.size(); i++) {
        cout << s[i];
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
