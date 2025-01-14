#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int cmp(pair<int, int>& a, pair<int, int>& b)
{
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>&, pair<int, int>&)>> q(cmp);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push({ x, i });
        }
        int res = n;
        int cnt = 0;
        int mx = q.top().first;
        while (!q.empty()) {
            auto p = q.top();
            q.pop();
            int tmp = p.second + cnt;
            res = min(tmp, res);
            cnt++;
        }
        cout << res << endl;
    }
}
