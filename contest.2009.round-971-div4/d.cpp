#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<bool>> coord(n + 5, vector<bool>(2, false));
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            coord[x][y] = true;
        }

        long long res = 0;
        for (int x = 0; x <= n; x++) {
            if (coord[x][1] && coord[x][0]) {
                res += n - 2;
            }
            if (x > 0) {
                if (coord[x][1] && coord[x - 1][0] && coord[x + 1][0]) {
                    res++;
                }
                if (coord[x][0] && coord[x - 1][1] && coord[x + 1][1]) {
                    res++;
                }
            }
        }
        cout << res << endl;
    }
}
