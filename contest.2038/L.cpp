// #include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define fi first
#define se second
#define pii pair<int, int>

const int maxn = 2e5 + 5;
int n, a[maxn], t, m, b[maxn], k, c[maxn];

int32_t main()
{
    int n;
    cin >> n;
    cout << n / 2 + n / 3 - n / 6 + (n + 1) / 2 + (n % 3 - n / 2 % 3 + n % 2) % 3 / 2;
}
