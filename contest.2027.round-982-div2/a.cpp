#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int w = 0, h = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            w = max(w, x);
            h = max(h, y);
        }
        cout << (w + h) * 2 << endl;
    }
}
