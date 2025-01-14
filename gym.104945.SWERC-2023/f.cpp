#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2)
{
    return p1.first > p2.first;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, string>> score;
    for (int i = 0; i < n; i++) {
        string s;
        int p;
        vector<int> e(6);
        cin >> s >> p;
        for (int j = 0; j < 6; j++)
            cin >> e[j];
        sort(e.begin(), e.end());
        int pts = p * 10;
        for (int j = 1; j < 5; j++) {
            pts += e[j];
        }
        score.push_back({ pts, s });
    }

    sort(score.begin(), score.end(), cmp);
    int i = 0;
    int last = score[0].first;
    for (int i = 0; i < n; i++) {
        if (score[i].first != last) {
            if (i > 2)
                break;
        }
        last = score[i].first;
        cout << score[i].second << " " << score[i].first << endl;
    }
}
