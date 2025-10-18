#include <algorithm>
#include <iostream>
#include <vector>

#define ll long long

using namespace std;
const int MAXN = 4e5 + 5;
const ll BASE = 4e5 + 5, MOD = 1e9 + 7;
ll POW[MAXN], h[MAXN], hr[MAXN];
bool mark[MAXN];
int n, k, a[MAXN];

ll hashSub(ll hashArr[MAXN], int l, int r) {
    return (hashArr[r] - hashArr[l - 1] * POW[r - l + 1] + MOD * MOD) % MOD;
}

int MEX(vector<int> &v) {
    sort(v.begin(), v.end());
    int mex = 1;
    for (auto x : v) {
        if (x == mex) {
            mex++;
        } else if (x > mex) {
            break;
        }
    }
    return mex;
}

void solve() {
    memset(mark, 0, sizeof(mark));
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    h[0] = 0;
    hr[0] = 0;
    for (int i = 1; i <= n; i++) {
        h[i] = (h[i - 1] * BASE + a[i]) % MOD;
        hr[i] = (hr[i - 1] * BASE + a[n - i + 1]) % MOD;
    }

    vector<int> f;
    for (int i = 2; i <= n; i++) {
        ll hashA = hashSub(h, i, n);
        ll hashB = hashSub(hr, 1, n - i + 1);
        if (hashA == hashB) {
            mark[a[i - 1]] = 1;
        }
    }
    int mex = 1;
    while (mark[mex]) {
        mex++;
    }
    if (mex > n) {
        cout << a[n - 1] << " ";
        a[n + 1] = a[n - 1];
    } else {
        cout << mex << " ";
        a[n + 1] = mex;
    }

    for (int i = 2; i <= k; i++) {
        vector<int> newpos;
        newpos.push_back(a[n + i - 1]);
        newpos.push_back(a[n + i - 2]);
        ll num = MEX(newpos);
        if (num > n) {
            cout << a[n + i - 2] << " ";
            a[n + i] = a[n + i - 2];
        } else {
            cout << num << " ";
            a[n + i] = num;
        }
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    POW[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        POW[i] = POW[i - 1] * BASE % MOD;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
