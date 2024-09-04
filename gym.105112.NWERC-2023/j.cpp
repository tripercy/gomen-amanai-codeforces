#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<double, vector<pair<int, int>>> getLines(vector<pair<int, int>>& points, double a)
{
    unordered_map<double, vector<pair<int, int>>> lines;

    for (auto point : points) {
        int x = point.first;
        int y = point.second;
        bool hasLine = false;
        double b = y - a * x;
        if (lines.find(b) == lines.end()) {
            lines[b] = vector<pair<int, int>>();
        }
        lines[b].push_back({ x, y });
    }

    return lines;
}

double getPath(unordered_map<double, vector<pair<int, int>>> lines)
{
    vector<int> bs;
    for (auto p : lines) {
        bs.push_back(p.first);
        sort(p.second.begin(), p.second.end());
    }
    sort(bs.begin(), bs.end());

    double res = 0;
    for (int i = 0; i < bs.size() - 1; i++) {
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++)
        cin >> points[i].first >> points[i].second;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = points[i].first, x2 = points[j].first;
            int y1 = points[i].second, y2 = points[j].second;
            double a = (double)(y1 - y2) / (double)(x1 - x2);
            auto lines = getLines(points, a);
        }
    }
}
