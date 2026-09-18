#include <bits/stdc++.h>
#define MULTITEST true
using namespace std;

#ifdef LOCAL
#define dbg(x) cout << "[debug] " << #x << " = " << (x) << endl
#else
#define dbg(x)
#endif

// #define int long long
#define ll long long
using pii = pair<int, int>;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    n *= 2;
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && s[(i + n - 1) % n] == '1') {
            i % 2 ? s2++ : s1++;
        } else if (s[i] == '1' && s[(i + 1) % n] == '1') {
            i % 2 ? s2++ : s1++;
        }
    }
    cout << s2 << " " << s1 << endl;
}

int main() {
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    if (MULTITEST) {
        cin >> t;
    }
    while (t--) {
        solve();
    }

    return 0;
}
