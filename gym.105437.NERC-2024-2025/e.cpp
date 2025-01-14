#include <iostream>
#include <vector>

using namespace std;

long long MOD = 1e9 + 7;

vector<long long> power;

long long get(int k)
{
    if (power[k] != -1) {
        return power[k];
    }

    power[k] = (get(k / 2) % MOD) * (get(k - k / 2) % MOD) % MOD;
    return power[k];
}

int main()
{
    int t;
    cin >> t;
    vector<int> N(t);

    power = vector<long long>(1e5 + 5, -1);
    power[0] = 1;
    power[1] = 2;

    for (int i = 0; i < t; i++) {
        cin >> N[i];
    }

    for (int i = 0; i < t; i++) {
        int k;
        cin >> k;
        int n = N[i];
        if (k == n || k == 0) {
            cout << 1 << endl;
            continue;
        }
        cout << get(k) << endl;
    }
}
