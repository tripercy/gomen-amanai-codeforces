#include <iostream>

using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << (n % 4 == 0 ? "Bob" : "Alice") << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
