#include <bits/stdc++.h>
#include <functional>
#include <iomanip>
#include <vector>

using namespace std;

void search(int d, int s, vector<int>& curr, vector<vector<int>>& combs)
{
    if (d == 0) {
        combs.push_back(vector<int>(curr));
        return;
    }

    for (int i = s; i <= 7 - d; i++) {
        curr.push_back(i);
        search(d - 1, i + 1, curr, combs);
        curr.pop_back();
    }
}

int main()
{
    vector<vector<bool>> cal(7, vector<bool>(24, false));

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 24; j++) {
            char c;
            cin >> c;
            cal[i][j] = c == '.';
        }
    }

    int d, h;
    cin >> d >> h;

    vector<int> curr;
    vector<vector<int>> combs;
    search(d, 0, curr, combs);
    double res = 0;
    for (auto comb : combs) {
        vector<int> df(24);
        for (auto day : comb) {
            for (int i = 0; i < 24; i++) {
                df[i] += cal[day][i];
            }
        }
        sort(df.begin(), df.end(), greater<int>());
        int s = 0;
        for (int i = 0; i < h; i++) {
            s += df[i];
        }
        res = max(res, (double)s / (d * h));
    }
    cout << setprecision(6) << res << endl;
}
