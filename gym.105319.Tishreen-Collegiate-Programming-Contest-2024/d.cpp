#include <bits/stdc++.h>

using namespace std;

int getBit(int i, int x)
{
    return (x >> i) & 1;
}

void search(int a[], vector<int>& segs, int l, int r, int k)
{
    cout << l << " " << r << " " << k << endl;
    if (l >= r) {
        segs.push_back(1);
        return;
    }

    if (k == -1) {
        segs.push_back(r - l);
        return;
    }

    int lastBit = getBit(k, a[l]);
    for (int i = l + 1; i <= r; i++) {
        if (getBit(k, a[i]) != lastBit) {
            search(a, segs, l, i - 1, k - 1);
            lastBit = getBit(k, a[i]);
            l = i;
        }
    }

    if (k == 0) {
        segs.push_back(r - l);
    } else {
        search(a, segs, l, r, k - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> segs;
    search(a, segs, 0, n - 1, 31);
    for (auto seg : segs) {
        cout << seg << " ";
    }
    cout << endl;
}
