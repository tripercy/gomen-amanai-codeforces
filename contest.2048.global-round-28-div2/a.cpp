#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 33 == 0) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
}
