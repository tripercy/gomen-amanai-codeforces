#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool query(int i, int x) {
    cout << "? " << i << " " << x << endl;
    cout.flush();
    bool res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> c0, c1, asking;
    unordered_set<int> available;
    for (int i = 1; i < n; i++) {
        asking.push_back(i);
        available.insert(i);
    }
    available.insert(n);
    int o = n;
    for (int i = 0; i < (int)log2(n); i++) {
        int x = (1 << i);
        c0.clear();
        c1.clear();
        for (int j : asking) {
            if (query(j, x)) {
                c1.push_back(j);
            } else {
                c0.push_back(j);
            }
        }
        // for (int a : c0) {
        //     cout << a << " ";
        // }
        // cout << endl;
        // for (int a : c1) {
        //     cout << a << " ";
        // }
        // cout << endl;
        unordered_set<int> tmp;
        int cnt1 = n / 2 + (n & 1);
        // cout << cnt1 << " " << c1.size() << endl;
        if (cnt1 != c1.size()) {
            for (int num : available) {
                if ((num & x) == 1) {
                    tmp.insert(num);
                }
            }
            asking.swap(c1);
        } else {
            for (int num : available) {
                if ((num & x) == 0) {
                    tmp.insert(num);
                }
            }
            asking.swap(c0);
        }
        available.swap(tmp);
        n >>= 1;
    }
    cout << "! " << *(available.begin()) << endl;
    cout.flush();
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
