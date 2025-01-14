#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int m, a, b, c;
        cin >> m >> a >> b >> c;
        int r1 = min(m, a);
        int r2 = min(m, b);
        int rL = m - r1 + m - r2;
        int rc = min(rL, c);
        cout << r1 + r2 + rc << endl;
    }
}
