#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < 4; j++) {
                if (s[j] == '#') {
                    res[i] = j;
                    break;
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            cout << res[i] + 1;
            cout << (i > 0 ? ' ' : '\n');
        }
    }
}
