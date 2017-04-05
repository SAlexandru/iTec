#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

inline bool cmp(const pair<int, int>& x, const pair<int, int>& y) {
    return x.first == y.first ? x.second < y.second : x.first < y.first;
}

int main() {
    vector<pair<int, int>> v;

    int N;
    for (cin >> N; N; --N) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 1});
        v.push_back({y, 2});
    }

    for (size_t i = 1; i < v.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (cmp(v[i], v[j])) {
               swap(v[i], v[j]);
            }
        }
    }


    int count = 0, sol = 0;

    for (const auto& x: v) {
        if (x.second == 1) ++count;
        else --count;
        sol = max(count, sol);
    }

    cout << sol << "\n";

    return 0;
}

