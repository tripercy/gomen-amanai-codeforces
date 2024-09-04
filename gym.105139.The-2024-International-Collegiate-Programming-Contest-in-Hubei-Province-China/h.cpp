#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>

const int N = 15, S = (1 << 20) + 10;
const int dx[4] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

int dists[S];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    map<pair<int, int>, vector<int>> mp;
    vector<vector<int>> states;
    vector<int> x(k + 1), y(k + 1), z(k + 1);
    vector<int> vc;
    memset(dists, -1, sizeof(dists));
    for (int i = 0; i < k; i++) {
        cin >> x[i] >> y[i] >> z[i];
        vc.push_back(z[i]);
    }
    for (int i = 0; i < k; i++) {
        mp[{ x[i], y[i] }].push_back(i);
        for (int j = 0; j < 4; j++) {
            int nxt_x = x[i] + dx[j], nxt_y = y[i] + dy[j];
            if (nxt_x < 1 || nxt_x > n || nxt_y < 1 || nxt_y > m)
                continue;
            mp[{ nxt_x, nxt_y }].push_back(i);
        }
    }
    for (auto [it, cur] : mp)
        states.push_back(cur);

    auto hfish = [&](vector<int> vec) {
        int res = 0;
        for (auto x : vec)
            res = 4 * res + x;
        return res;
    };

    queue<vector<int>> q;
    q.push(vc);
    dists[hfish(vc)] = 0;
    unordered_map<string, bool> visited;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        string s;
        for (int f : cur) {
            s += f - '0';
        }
        if (visited.find(s) != visited.end() || visited[s]) {
            continue;
        }
        visited[s] = true;
        int hc = hfish(cur);
        for (auto& vec : states) {
            auto nxt = cur;
            for (auto x : vec) {
                if (nxt[x])
                    nxt[x]--;
            }
            int hn = hfish(nxt);
            if (~dists[hn])
                continue;
            dists[hn] = dists[hc] + 1;
            q.push(nxt);
        }
    }
    cout << dists[0] << '\n';
}
