#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int x, y, k;
        cin >> x >> y >> k;
        int a = ceil((double)x / k);
        int b = ceil((double)y / k);
        int c = a > b;
        cout << max(a, b) * 2 - c << endl;
    }
}
