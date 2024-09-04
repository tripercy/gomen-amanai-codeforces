#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e6 + 10;

vector<string> b[N];

void combine(int x, int y) {
    string xx = b[x].back(), yy = b[y].back();
    b[x].pop_back();
    b[y].pop_back();
    string combination = "(" + xx + "+" + yy + ")";
    b[x + y].push_back(combination);
}

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int x : a) {
        b[x].push_back(to_string(x));
    }

    while (!b[1].empty()) {
        if (!b[2].empty())
            combine(1, 2);
        else if (b[1].size() > 1)
            combine(1, 1);
        else if (n > 1) {
            int cur = 2;
            while (b[cur].empty()) cur++;
            combine(1, cur);
        } else
            break;
    }

    bool flag = true;
    for (auto v : b) {
        for (string s : v) {
            if (flag)
                flag = false;
            else
                cout << "*";
            cout << s;
        }
    }
    cout << '\n';
}