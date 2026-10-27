#include <iostream>

using namespace std;
const int MAXN = 2e5 + 5;
int n, q;
int p[MAXN], idx[MAXN];

void solve() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        idx[p[i]] = i;
    }
    int l, r, k;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r >> k;
        int pos = idx[k];
        if (pos < l || pos > r) {
            cout << "-1 ";
            continue;
        }
        int lcount = 0, gcount = 0;
        int lleft = k - 1, gleft = n - lleft - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (m > pos) {
                r = m - 1;
                if (p[m] < k) {
                    lcount++;
                    lleft--;
                } else {
                    gleft--;
                }
            } else if (m < pos) {
                l = m + 1;
                if (p[m] > k) {
                    gcount++;
                    gleft--;
                } else {
                    lleft--;
                }
            } else if (m == pos) {
                l = r = pos;
                break;
            }
            // cout << m << " " << p[m] << " " << gcount << " " << lcount <<
            // endl;
        }
        int diff = abs(gcount - lcount);
        if (gcount > lcount && diff > lleft) {
            cout << "-1 ";
            continue;
        }
        if (lcount > gcount && diff > gleft) {
            cout << "-1 ";
            continue;
        }
        cout << diff * 2 + min(gcount, lcount) * 2 << " ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
