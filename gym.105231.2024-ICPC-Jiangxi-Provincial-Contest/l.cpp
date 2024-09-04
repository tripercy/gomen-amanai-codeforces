#include <bits/stdc++.h>
#include <climits>
#include <queue>

using namespace std;

class Cmp {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        return p1.second > p2.second;
    }
};

int main()
{
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    int a[n + 1];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int g[k], l[k], r[k];
    for (int i = 0; i < k; i++) {
        cin >> g[i] >> l[i] >> r[i];
    }

    vector<vector<pair<int, int>>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        edges[u].push_back({ v, d });
        edges[v].push_back({ u, d });
    }

    vector<vector<int>> dist(k, vector<int>(n + 1, INT_MAX));

    for (int i = 0; i < k; i++) {
        int gate = g[i];
        dist[i][gate] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp> pq;
        pq.push({ gate, 0 });

        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int u = top.first, curr = top.second;
            for (auto edge : edges[u]) {
                int v = edge.first;
                int ds = edge.second;

                if (curr + ds < dist[i][v]) {
                    dist[i][v] = curr + ds;
                    pq.push({ v, curr + ds });
                }
            }
        }
    }

    vector<vector<int>> tmp_gates;
    int start = 0, end = 0;
    for (int time = 1; time <= t; time++) {
        vector<int> open;
        for (int i = 0; i < k; i++) {
            if (time >= l[i] && time <= r[i]) {
                open.push_back(i);
            }
        }
        tmp_gates.push_back(open);
    }

    vector<int> sizes;
    vector<vector<int>> gates;
    for (int i = 0; i < tmp_gates.size(); i++) {
        if (gates.empty() || gates[gates.size() - 1].size() != tmp_gates[i].size()) {
            gates.push_back(tmp_gates[i]);
            sizes.push_back(1);
            continue;
        }
        bool flag = true;
        for (int j = 0; j < tmp_gates[i].size(); j++) {
            if (tmp_gates[i][j] != gates[gates.size() - 1][j]) {
                flag = false;
                gates.push_back(tmp_gates[i]);
                sizes.push_back(1);
                break;
            }
        }
        if (flag) {
            sizes[sizes.size() - 1] += 1;
        }
    }

    for (int i = 0; i < sizes.size(); i++) {
        auto open_gates = gates[i];
        auto sz = sizes[i];

        long long ans = -1;
        if (open_gates.size() > 0) {
            ans = 0;
            for (int j = 1; j <= n; j++) {
                int d = INT_MAX;
                for (auto gate : open_gates) {
                    d = min(d, dist[gate][j]);
                }
                ans += d * a[j - 1];
            }
        }

        for (int j = 0; j < sz; j++) {
            cout << ans << endl;
        }
    }
}
