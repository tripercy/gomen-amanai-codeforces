#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin >> m;
    bool black = true;
    vector<vector<int>> board(19, vector<int>(19, 0));
    vector<vector<int>> d { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    while (m--) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        board[x][y] = 2 - black;
        int a = 2 - black, b = 2 - !black;

        int res = 0;
        for (auto p : d) {
            int nx = x + p[0], ny = y + p[1];
            if (nx < 0 || ny < 0 || nx >= 19 || ny >= 19 || board[nx][ny] != b) {
                continue;
            }
            bool flag = false;
            vector<vector<bool>> visited(19, vector<bool>(19, false));
            queue<pair<int, int>> q;
            q.push({ nx, ny });
            while (!q.empty()) {
                auto top = q.front();
                q.pop();
                if (visited[top.first][top.second]) {
                    continue;
                }
                visited[top.first][top.second] = true;
                for (auto dir : d) {
                    int dx = top.first + dir[0];
                    int dy = top.second + dir[1];
                    if (dx < 0 || dy < 0 || dx >= 19 || dy >= 19) {
                        continue;
                    }
                    if (board[dx][dy] == 0) {
                        flag = true;
                        break;
                    }
                    if (board[dx][dy] != b || visited[dx][dy]) {
                        continue;
                    }
                    q.push({ dx, dy });
                }
                if (flag)
                    break;
            }
            if (flag) {
                continue;
            }
            for (int i = 0; i < 19; i++) {
                for (int j = 0; j < 19; j++) {
                    if (visited[i][j]) {
                        board[i][j] = 0;
                        res++;
                    }
                }
            }
        }
        if (black) {
            cout << "0 " << res << endl;
        } else {
            cout << res << " 0" << endl;
        }
        black = !black;
    }
}
