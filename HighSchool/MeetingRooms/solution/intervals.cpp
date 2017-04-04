#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

int main() {
    vector<pair<int, int>> v;

    int N;
    for (cin >> N; N; --N) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, 1});
        v.push_back({y, 2});
    }

    sort(v.begin(), v.end());

    int count = 0, sol = 0;

    for (const auto& x: v) {
        if (x.second == 1) ++count;
        else --count;
        sol = max(count, sol);
    }

    cout << sol << "\n";

    return 0;
}

