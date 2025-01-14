#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int res = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x == 0) {
                flag = true;
                continue;
            }
            if (flag) {
                res++;
                flag = false;
            }
        }
        cout << min(res, 2) << endl;
    }
}
