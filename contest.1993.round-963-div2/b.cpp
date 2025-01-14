#include <algorithm>
#include <iostream>
#include <vector>

#define int long long

using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> evens;
        int mxo = -1;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                evens.push_back(a[i]);
            } else {
                mxo = max(mxo, a[i]);
            }
        }
        if (evens.size() == 0 || mxo == -1) {
            cout << 0 << endl;
            continue;
        }
        sort(evens.begin(), evens.end());
        int res = 0;
        for (int i = 0; i < evens.size(); i++) {
            // cout << mxo << endl;
            if (evens[i] < mxo) {
                res++;
                mxo = mxo + evens[i];
            } else {
                res = evens.size() + 1;
                break;
            }
        }
        cout << res << endl;
    }
}
