#include <bits/stdc++.h>
#define MULTITEST false
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[DBG] " << #x << ": " << (x) << endl
#define dump(a)                                                                \
    do {                                                                       \
        cout << "[DBG] " << #a << ": ";                                        \
        for (auto &x : a)                                                      \
            cout << x << " ";                                                  \
        cout << endl;                                                          \
    } while (0)
#else
#define dbg(x)
#define dump(a)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int cnt[3] = {0, 0, 0};
    for (char c : s) {
        cnt[c - '0']++;
    }
    int m = n / 3;
    cnt[0] -= m;
    cnt[1] -= m;
    cnt[2] -= m;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n && cnt[i] < 0; j++) {
            int x = s[j] - '0';
            if (x > i && cnt[x] > 0) {
                s[j] = i + '0';
                cnt[x]--;
                cnt[i]++;
            }
        }
    }
    for (int i = 2; i >= 0; i--) {
        for (int j = n - 1; j >= 0 && cnt[i] < 0; j--) {
            int x = s[j] - '0';
            if (x < i && cnt[x] > 0) {
                s[j] = i + '0';
                cnt[x]--;
                cnt[i]++;
            }
        }
    }
    cout << s << endl;
}

int32_t main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    int TEST = 1;
    if (!MULTITEST) {
        solve();
        return 0;
    }
    cin >> t;
    while (t--) {
        dbg(TEST);
        TEST++;
        solve();
    }

    return 0;
}
