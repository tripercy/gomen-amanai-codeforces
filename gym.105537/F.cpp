#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 2, 10000);
    for (int i = 0; i < n; i++) {
        int h, m;
        char c;
        cin >> h >> c >> m;
        m = h * 60 + m;
        a[i] = m;
    }

    int res = 2;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 2] - a[i] <= 10) {
            res = 0;
            break;
        }
        if (a[i + 1] - a[i] <= 10) {
            res = 1;
        }
    }
    cout << res;
}
