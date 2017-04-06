#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>


using namespace std;

int main() {
    vector<pair<int, int>> v;

    int N;

    cin >> N;
    assert(1 <= N && N <= 100000);
    for (; N; --N) {
        int x, y;
        cin >> x >> y;

        assert(x < y);
        v.push_back({x, 2});
        v.push_back({y, 1});
    }

    sort(v.begin(), v.end());

    int count = 0, sol = 0;

    for (const auto& x: v) {
        if (x.second == 2) ++count;
        else --count;
        sol = max(count, sol);
    }

    cout << sol << "\n";

    return 0;
}

