#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    set<int> a;
    cin >> s;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    int last = 1;
    for (char c : s) {
        int pos = last;
        if (c == 'A') {
            pos++;
            last = pos;
            a.insert(pos);
        } else {
            pos++;
            while (a.find(pos) != a.end()) {
                pos++;
            }
            a.insert(pos);
            while (a.find(pos) != a.end()) {
                pos++;
            }
            last = pos;
        }
    }
    cout << a.size() << endl;
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
