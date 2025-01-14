#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        s = " " + s;
        vector<pair<int, int>> p_seg, s_seg;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'p') {
                p_seg.push_back({ 1, i });
            }
            if (s[i] == 's') {
                s_seg.push_back({ i, n });
            }
        }
        bool flag = true;
        for (auto ps : p_seg) {
            for (auto ss : s_seg) {
                if (!(ps.first >= ss.first && ps.second <= ss.second) && !(ss.first >= ps.first && ss.second <= ps.second)) {
                    flag = false;
                    break;
                }
            }
            if (!flag) {
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
