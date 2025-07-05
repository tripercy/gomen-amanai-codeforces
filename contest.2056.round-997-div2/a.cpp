#include <iostream>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    int w = m, h = m;
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        w += x;
        h += y;
    }
    cout << (w + h) * 2 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
