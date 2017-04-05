#include <queue>
#include <array>
#include <vector>
#include <iterator>
#include <iostream>
#include <algorithm>

// uncomment to disable assert()
// // #define NDEBUG
#include <cassert>


using namespace std;

constexpr int NMAX = 111;

using Graph = array<vector<int>, NMAX>;

array<int, NMAX> bfs(const Graph& G, const int& start) {
    array<int, NMAX> dist;

    fill(dist.begin(), dist.end(), -1);

    dist[start] = 0;

    queue<int> q;
    for (q.push(start); !q.empty(); q.pop()) {
        for (const auto& x: G[q.front()]) {
            if (dist[x] < 0) {
                dist[x] = dist[q.front()] + 1;
                q.push(x);
            }
        }
    }

    return dist;
}

int main() {
    Graph G;
    int N, M, start;

    cin >> N >> M >> start;

    assert(1 <= N && N <= 100);
    assert(1 <= M && M <= 100000);
    assert(1 <= start && start <= N);

    while (M --) {
        int x, y;
        cin >> x >> y;
        assert(1 <= x && x <= N);
        assert(1 <= y && y <= N);

        G[x].push_back(y);
        G[y].push_back(x);
    }

    auto ans = bfs(G, start);
    
    copy(ans.begin() + 1, ans.begin() + N + 1, ostream_iterator<int>{cout, " "});

    return 0;
}
