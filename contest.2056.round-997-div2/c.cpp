#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> res(n);
    int l = (n + 1) / 2;
    res[0] = 1;
    res[l + 1] = 1;
    for (int i = 1; i <= l; i++) {
        res[i] = i;
    }
    for (int i = l + 2; i < n; i++) {
        res[i] = res[i - l];
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
