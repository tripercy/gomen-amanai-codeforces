#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    string tiles;
    cin >> tiles;
    unordered_map<string, int> tile_cnt;
    for (int i = 0; i < 28; i += 2) {
        string tile = tiles.substr(i, 2);
        tile_cnt[tile]++;
    }
    vector<string> terminalAndHonors = {"1p", "9p", "1s", "9s", "1m", "9m", "1z", "2z", "3z", "4z", "5z", "6z", "7z"};
    bool has_all_13 = true;
    bool has_extra = false;
    for (auto& tile : terminalAndHonors) {
        if (tile_cnt[tile] == 0) {
            has_all_13 = false;
            break;
        }
        if (tile_cnt[tile] > 1) {
            if (has_extra) {
                has_all_13 = false;
                break;
            }
            has_extra = true;
        }
    }
    bool is_seven_pairs = true;
    int pair_cnt = 0;
    for (auto& pair : tile_cnt) {
        if (pair.second == 2) {
            pair_cnt++;
        } else if (pair.second != 0) {
            is_seven_pairs = false;
            break;
        }
    }
    if (has_all_13 && has_extra) {
        cout << "Thirteen Orphans" << endl;
    } else if (is_seven_pairs && pair_cnt == 7) {
        cout << "7 Pairs" << endl;
    } else {
        cout << "Otherwise" << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}