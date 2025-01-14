#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (a > b)
            swap(a, b);
        if ((b - a) % 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
