#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> res(n, -1);
        int i = 1;
        for (int j = k - 1; j < n; j += k) {
            res[j] = i;
            i++;
        }
        for (int j = 0; j < n; j++) {
            if (res[j] == -1) {
                res[j] = i;
                i++;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
}
