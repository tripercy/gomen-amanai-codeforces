#include <algorithm>
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
        sort(a.begin(), a.end());
        int m = (n - 1) / 2;
        int res = 1;
        while (a[m] == a[m + 1] && m < n - 1) {
            m++;
            res++;
        }
        cout << res << endl;
    }
}
