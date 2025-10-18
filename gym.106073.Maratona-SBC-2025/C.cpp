#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    int x = 0;
    for (int i = n; i >= 0; i--) {
        bool on;
        cin >> on;
        if (on) {
            x |= (1 << i);
        }
    }

    int res = 0;
    while (x != 1) {
        res += 1;
        if (x & 1) {
            x = (x ^ ((x << 1) + 1));
        } else {
            x = (x >> 1);
        }
    }
    cout << res << endl;

    return 0;
}
