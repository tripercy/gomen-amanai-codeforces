#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    vector<int> cnt(n + 1, 0);
    for (int x : a) {
        cnt[x]++;
    }
    int mex = 0;
    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0) {
            mex = i;
            break;
        }
    }
    vector<int> grad(n + 1, 0);
    for (int i = 0; i < mex; i++) {
        grad[cnt[i]]++;
        grad[n - i]--;
    }
    vector<int> res(n + 1);
    res[0] = 1;
    for (int i = 1; i <= n; i++) {
        res[i] = res[i - 1] + grad[i];
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
}

int main(int argc, char *argv[]) {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
