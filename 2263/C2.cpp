// https://codeforces.com/blog/entry/156688
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void tc() {
    int n;
    cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    vector<pair<int, int>> goodivs;
    vector<pair<int, int>> badivs;
    for (int i = 1; i <= n; i++) {
        if (b[i] > (n - 1) / i + 1) { // Invalid input
            cout << 0 << endl;
            return;
        }
        badivs.push_back({b[i] * i, (b[i] + 1) * i - 1});
        for (int j = 0; j < b[i]; j++) {
            goodivs.push_back({j * i, (j + 1) * i - 1});
        }
    }

    vector<int> diff(n + 1);
    for (auto [l, r] : badivs) {
        diff[min(n, l)]++;
        diff[min(n, r + 1)]--;
    }
    int csm = 0;          // current sum for pfs: pfs[i] = 0 -> i is good number
    vector<int> goodNums; // number that CAN appear in the final sets
    for (int i = 0; i < n; i++) {
        csm += diff[i];
        if (csm == 0) {
            goodNums.push_back(i);
        }
    }

    set<pair<int, int>> st;
    sort(goodivs.begin(), goodivs.end(),
         [&](pair<int, int> iv, pair<int, int> iv2) {
             return iv.second - iv.first < iv2.second - iv2.first;
         }); // sort by size
             // => when loop through array from beginning, the size of
             // interval[i] is always <= interval[j] (j > i) AND there is no
             // duplicate interval
             // => interval[i] NEVER contains interval[j] (j > i)

    for (auto [l, r] : goodivs) {
        auto it = st.lower_bound({l, 0}); // the interval it with it.l >= l
        if (it != st.end() &&
            it->second <=
                r) { // if internal it is contained inside [l, r], skip [l, r]
            continue;
        }
        st.insert({l, r});
    } // => only intervals that don't contain other intervals are kepts

    vector<pair<int, int>> impivs(st.begin(), st.end()); // NOTE: impivs starts from 0: all intervals that needs to be satisfied
    int l = 0, r = 0;
    vector<int> dp(impivs.size() + 1, 0); // dp[i]: the number of possible sets if all first i (0 -> i - 1) intervals are satisfied, but interval i is not
    dp[0] = 1; // empty set always make interval[0] not satisfied
    int poss = 1; // current count of valid set
    for (int i : goodNums) {
        while (l < impivs.size() && impivs[l].second < i) { // loop to closest interval that contains i
            poss += MOD - dp[l]; // dp[l] means interval[l] is not satisfied, which is invalid => remove dp[l] from result
            poss %= MOD;
            l++; 
        }
        while (r < impivs.size() && impivs[r].first <= i) // loop to the closest interval that doesn't contain i
            r++;
        dp[r] += poss; // adding i will make all sets inside [l, r - 1] satisfied, but not r
        dp[r] %= MOD;
        poss += poss; // each number i naively doubles the number of possible sets
        poss %= MOD;
    }
    cout << dp[impivs.size()] << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        tc();
}
