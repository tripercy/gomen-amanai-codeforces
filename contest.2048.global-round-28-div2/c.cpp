#include <iostream>

using namespace std;

string _xor(string a, string b)
{
    string res("", a.size());
    for (int i = 0; i < a.size(); i++) {
        res[i] = a[i] != b[i] ? '1' : '0';
    }
    return res;
}

bool gt(string a, string b)
{
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < b[i]) {
            return false;
        }
        if (a[i] > b[i]) {
            return true;
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        string a = "";

        bool hasZero = false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                hasZero = true;
                a = s.substr(i, n - i + 1);
                break;
            }
        }
        if (!hasZero) {
            cout << 1 << " " << n << " 1 1\n";
            continue;
        }
        int l, r;
        string mx = a;
        for (int i = 0; i < n - a.size(); i++) {
            if (s[i] != '1') {
                continue;
            }
            string b = s.substr(i, a.size());
            string x = _xor(a, b);
            // cout << a << " " << b << " " << x << endl;
            if (gt(x, mx)) {
                mx = x;
                l = i;
                r = i + a.size() - 1;
            }
        }
        cout << 1 << " " << n << " " << l + 1 << " " << r + 1 << endl;
    }
}
