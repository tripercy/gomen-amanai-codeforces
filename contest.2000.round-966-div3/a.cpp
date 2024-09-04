#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string n;
        cin >> n;
        if (n.size() < 3) {
            cout << "NO\n";
            continue;
        }
        if (n[0] != '1' || n[1] != '0' || n[2] == '0') {
            cout << "NO\n";
            continue;
        }
        if (n.size() == 3 && n[2] == '1') {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}
