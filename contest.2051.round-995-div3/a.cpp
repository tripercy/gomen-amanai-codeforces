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
        vector<int> a(n), b(n + 1, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i + 1]) {
                res += a[i] - b[i + 1];
            }
        }
        cout << res << endl;
    }
}
