#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        int res = n / (a + b + c);
        res *= 3;
        n %= a + b + c;
        if (n > 0) {
            if (n <= a) {
                res += 1;
            } else if (n <= a + b) {
                res += 2;
            } else {
                res += 3;
            }
        }
        cout << res << endl;
    }
}
