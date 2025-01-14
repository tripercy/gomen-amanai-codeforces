#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            int x = a[i], y = a[i + 1];
            if (x < y) {
                swap(x, y);
            }
            if (2 * y > x) {
                flag = true;
                break;
            }
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
}
