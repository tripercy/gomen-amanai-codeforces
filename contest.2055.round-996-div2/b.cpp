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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        bool flag = true;
        int s = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] - s < b[i]) {
                if (s > 0) {
                    flag = false;
                    break;
                } else {
                    s = b[i] - a[i];
                    a[i] = b[i] + s;
                }
            }
        }
        // cout << s << endl;
        if (flag && s > 0) {
            for (int i = 0; i < n; i++) {
                if (a[i] - s < b[i]) {
                    flag = false;
                    break;
                }
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
}
