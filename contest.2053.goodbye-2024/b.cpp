#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> l(n), r(n);
        vector<int> range;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
            if (l[i] == r[i]) {
                range.push_back(l[i]);
                cnt[l[i]]++;
            }
        }

        sort(range.begin(), range.end());
        // for (int i = 0; i < range.size(); i++) {
        //     cout << range[i] << endl;
        // }
        vector<pair<int, int>> segs;
        for (int i = 0; i < range.size(); i++) {
            int l = range[i];
            while (i + 1 < range.size() && range[i + 1] <= range[i] + 1) {
                i++;
            }
            int r = range[i];
            // cout << i << " " << l << " " << r << endl;
            segs.push_back({ l, r });
        }
        // for (auto p : segs) {
        //     cout << p.first << " " << p.second << endl;
        // }
        if (segs.empty()) {
            for (int i = 0; i < n; i++) {
                cout << 1;
            }
            cout << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (l[i] == r[i]) {
                cout << (cnt[l[i]] == 1);
            } else {
                // int j = lower_bound(segs.begin(), segs.end(), pair<int, int>(l[i], 0)) - segs.begin();
                // cout << l[i] << " " << r[i] << " " << segs[j].first << " " << segs[j].second << endl;
                bool flag = true;
                for (auto p : segs) {
                    if (p.first <= l[i] && p.second >= r[i]) {
                        flag = false;
                        break;
                    }
                }
                cout << flag;
            }
        }
        cout << endl;
    }
}
