#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> depth(n, 0);
    depth[1] = 1;
    int par = 0;
    for (int i = 2; i < n; i++) {
        if (a[i] < a[i - 1]) {
            par++;
        }
        depth[i] = depth[par] + 1;
        // cout << i << " " << depth[i] << endl;
    }
    cout << depth[n - 1] << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
