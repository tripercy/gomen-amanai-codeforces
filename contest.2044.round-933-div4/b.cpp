#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string res = s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'p') {
                res[s.size() - 1 - i] = 'q';
            } else if (s[i] == 'q') {
                res[s.size() - 1 - i] = 'p';
            } else {
                res[s.size() - 1 - i] = 'w';
            }
        }
        cout << res << endl;
    }
}
