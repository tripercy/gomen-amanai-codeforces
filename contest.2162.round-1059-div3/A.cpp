#include <iostream>

using namespace std;

const int MAXN = 15;
int n;
int a[MAXN], pref[MAXN];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i];
    }

    int ans = 0;
    for (int l = 1; l <= n; l++) {
        for (int r = l; r <= n; r++) {
            int s = pref[r] - pref[l - 1];
            int tmp = s / (r - l + 1);
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
