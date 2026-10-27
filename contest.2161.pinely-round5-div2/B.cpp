#include <iostream>
#include <queue>
#include <vector>

#define pii pair<int, int>

using namespace std;
const int MAXN = 205;
int n;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
vector<string> grid;

bool chk(int r, int c) { return r >= 0 && c >= 0 && r < n && c < n; }

bool good(vector<string> grid) {
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int r = -1, c = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                r = i, c = j;
                if (chk(i - 1, j) && chk(i + 1, j) &&
                    grid[i - 1][j] == grid[i + 1][j] && grid[i - 1][j] == '#') {
                    return false;
                }
                if (chk(i, j - 1) && chk(i, j + 1) &&
                    grid[i][j - 1] == grid[i][j + 1] && grid[i][j + 1] == '#') {
                    return false;
                }
            }
        }
    }
    if (r == -1) {
        return true;
    }
    queue<pii> q;
    q.push({r, c});
    vis[r][c] = true;
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int nr = p.first + dr[d], nc = p.second + dc[d];
            if (!chk(nr, nc) || grid[nr][nc] != '#' || vis[nr][nc]) {
                continue;
            }
            q.push({nr, nc});
            vis[nr][nc] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '#' && !vis[i][j]) {
                return false;
            }
        }
    }

    return true;
}

vector<string> fillGrid(int r, int c, int dc, int dr) {
    vector<string> filled(grid.begin(), grid.end());
    while (chk(r, c)) {
        filled[r][c] = '#';
        if (chk(r + dr, c)) {
            filled[r + dr][c] = '#';
        }
        r++;
        c += dc;
    }
    return filled;
}

void solve() {
    cin >> n;
    grid = vector<string>(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    bool found = false;
    int i, j, r, c;
    for (i = 0; i < n && !found; i++) {
        for (j = 0; j < n; j++) {
            if (grid[i][j] == '#') {
                r = i, c = j;
                found = true;
                break;
            }
        }
    }
    auto g1 = fillGrid(r, c, -1, -1);
    auto g2 = fillGrid(r, c, -1, 1);
    auto g3 = fillGrid(r, c, 1, -1);
    auto g4 = fillGrid(r, c, 1, 1);
    // for (string s : g1) {
    //     cout << s << endl;
    // }
    // cout << " " << good(grid) << " " << good(g1) << " " << good(g2) << " "
    //      << good(g3) << " " << good(g4) << " " << endl;
    if (good(grid) || good(g1) || good(g2) || good(g3) || good(g4)) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
