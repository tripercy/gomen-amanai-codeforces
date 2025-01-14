#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 3 == 0) {
        cout << n / 3 << endl;
        while (n) {
            n -= 3;
            cout << 3 << " ";
        }
    } else if (n % 3 == 2) {
        cout << n / 3 + 1 << endl;
        while (n > 2) {
            n -= 3;
            cout << 3 << " ";
        }
        cout << 2;
    } else {
        cout << n / 3 + 1 << endl;
        while (n > 4) {
            n -= 3;
            cout << 3 << " ";
        }
        cout << "2 2";
    }
}
