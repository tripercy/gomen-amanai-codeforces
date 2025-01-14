#include <iostream>
#include <vector>

using namespace std;

int mex(int l, int r)
{
    for (int i = 0; i < 3; i++) {
        if (i != l && i != r) {
            return i;
        }
    }
    return 3;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> res(n, -1);
        res[x - 1] = 0;
        res[y - 1] = 1;
        int i = x + 1;
        for (int cnt = 0; cnt < n + 5; cnt++) {
            if (res[i] == -1) {
                int l = res[(i - 1 + n) % n];
                int r = res[(i + 1) % n];
                res[i] = mex(l, r);
            }
            i = (i + 1) % n;
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
