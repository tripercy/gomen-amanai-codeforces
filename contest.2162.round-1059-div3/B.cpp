#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            res.push_back(i + 1);
        }
    }
    cout << res.size() << endl;
    for (int x : res) {
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
