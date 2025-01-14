#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> deck1(n * k);
    vector<vector<int>> rev(n + 1);

    for (int i = 0; i < n * k; i++) {
        cin >> deck1[i];
    }

    for (int i = 0; i < n * k; i++) {
        int x;
        cin >> x;
        rev[x].push_back(i);
    }

    vector<int> dp = { -1 };
    for (int i = 0; i < n * k; i++) {
        for (int j = k - 1; j >= 0; j--) {
            int y = rev[deck1[i]][j];
            if (dp[dp.size() - 1] < y) {
                dp.push_back(y);
            } else {
                int l = 0, r = dp.size();
                int m = (r + l) / 2;
                while (true) {
                    m = (r + l) / 2;
                    if (dp[m - 1] >= y) {
                        r = m;
                    } else if (dp[m] < y) {
                        l = m;
                    } else {
                        break;
                    }
                }
                dp[m] = y;
            }
        }
    }

    cout << dp.size() - 1 << endl;
}
