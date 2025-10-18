#include <iostream>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    if (k > n / 2) {
        cout << "Alice\n";
        return;
    }
    int cnt = 0;
    for (char c : s) {
        cnt += c == '1';
    }
    if (cnt <= k) {
        cout << "Alice\n";
        return;
    }
    cout << "Bob\n";
    return;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
