#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    int s = v[0] + v[1] + v[2];
    if (s % 2) {
        cout << -1;
        return 0;
    }

    sort(v.begin(), v.end());
    int res = v[0];

    if (v[1] + v[0] < v[2]) {
        res += (v[2] - v[1] - v[0]) / 2;
    }
    cout << res;

    return 0;
}
