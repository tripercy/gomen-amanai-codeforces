#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> res(n, -1);

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        int pos = n - 1;
        for (int j = i; j < n; j++) {
            if (s[j] == '1') {
                while (res[pos] != -1) {
                    pos--;
                }
                pos--;
            }
        }
        while (res[pos] != -1) {
            pos--;
        }
        res[pos] = i;
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
