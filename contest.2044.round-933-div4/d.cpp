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
        vector<bool> vis(n + 1, false);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int p = 1;
        for (int i = 0; i < n; i++) {
            if (vis[a[i]]) {
                while (vis[p]) {
                    p++;
                }
                cout << p << " ";
                vis[p] = true;
            } else {
                cout << a[i] << " ";
                vis[a[i]] = true;
            }
        }
        cout << endl;
    }
}
