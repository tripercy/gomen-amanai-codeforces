#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ca = 0, cb = 0, cc = 0, cd = 0;
        for (char c : s) {
            if (c == 'A') {
                ca++;
            } else if (c == 'B') {
                cb++;
            } else if (c == 'C') {
                cc++;
            } else if (c == 'D') {
                cd++;
            }
        }
        cout << min(n, ca) + min(n, cb) + min(n, cc) + min(n, cd) << endl;
    }
}
