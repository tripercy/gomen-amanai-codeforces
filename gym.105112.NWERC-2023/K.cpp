#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 510;

bool vis[N][N][2];

void dfs(vector<int> dx, vector<int> dy, int x, int y, int idx, int n) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (vis[x][y][idx]) return;
    vis[x][y][idx] = 1;

    for (int j = 8 * idx; j < 8 * idx + 8; j++) {
        dfs(dx, dy, x + dx[j], y + dy[j], 1 - idx, n);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    vector<int> dx = {a, a, -a, -a, b, b, -b, -b, c, c, -c, -c, d, d, -d, -d};
    vector<int> dy = {b, -b, b, -b, a, -a, a, -a, d, -d, d, -d, c, -c, c, -c};

    dfs(dx, dy, 0, 0, 0, n);
    dfs(dx, dy, 0, 0, 1, n);

    int ans = 0;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            ans += max(vis[x][y][0], vis[x][y][1]);
        }
    }

    cout << ans << '\n';
}