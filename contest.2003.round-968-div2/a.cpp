#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        if (s[0] == s[s.size() - 1]) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
