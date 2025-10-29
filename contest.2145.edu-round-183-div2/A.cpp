#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << (3 - (n % 3)) % 3 << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
