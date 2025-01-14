#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int res = 0;
    int i = 0;
    while (i < min(s.size(), t.size()) && s[i] == t[i]) {
        i++;
    }

    res += i;
    res += s.size() - i + t.size() - i + 1;

    cout << res << endl;
}
