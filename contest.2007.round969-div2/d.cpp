#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    string s;
    cin >> s;
    s = " " + s;

    vector<int> par(n + 1, -1);
    vector<bool> visited(n + 1, false);
    stack<int> st;
    st.push(1);

    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (visited[top]) {
            continue;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
