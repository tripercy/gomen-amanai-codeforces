#include <bits/stdc++.h>

using namespace std;

int query(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if (res == -1) {
        exit(0);
    }

    return res;
}

void solve()
{
    int n;
    scanf("%d", &n);

    queue<pair<int, int>> q;
    vector<int> par(n + 1, -1);
    int found = 0;
    while (found < n - 1) {
        if (q.empty()) {
            int i = 2;
            for (; i < n; i++) {
                if (par[i] == -1)
                    break;
            }
            q.push({ 1, i });
        } else {
            auto p = q.front();
            q.pop();
            int a = p.first, b = p.second;
            if ((a == 1 && par[b] != -1) || (par[a] != -1 && par[b] != -1)) {
                continue;
            }
            int x = query(a, b);
            if (x == a) {
                par[b] = a;
                found += 1;
                continue;
            }
            if (x == b) {
                par[a] = b;
                found += 1;
                continue;
            }
            if (par[x] != a && par[a] != x) {
                q.push({ a, x });
            }
            if (par[x] != b && par[b] != x) {
                q.push({ x, b });
            }
        }
    }

    printf("!");
    for (int i = 2; i <= n; i++) {
        printf(" %d %d", par[i], i);
    }
    printf("\n");
    fflush(stdout);
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
