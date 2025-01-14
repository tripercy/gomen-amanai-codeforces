#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

#define int long long

int32_t main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a;
            b = a + i;
            pq.push({ b, b + i });
        }
        int res = n;
        unordered_set<int> s;
        s.insert(n);
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            if (s.find(p.first) != s.end()) {
                s.insert(p.second);
                res = max(res, p.second);
            }
        }
        cout << res << endl;
    }
}
