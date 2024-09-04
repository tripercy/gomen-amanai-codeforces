#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

bool cmp(pair<char, int> p1, pair<char, int> p2) {
    return p1.second > p2.second;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        string res = "";
        unordered_map<char, int> mp;
        for (auto c : s) mp[c]++;
        vector<pair<char, int>> v (mp.begin(), mp.end());
        sort(v.begin(), v.end(), cmp);

        while (!v.empty()) {
            for (int i = v.size() - 1; i >= 0; i--) {
                res += v[i].first;
                v[i].second--;
            }
            while(!v.empty() && v[v.size() -1].second == 0) {
                v.pop_back();
            }
        }

        cout << res << endl;
    }
}
