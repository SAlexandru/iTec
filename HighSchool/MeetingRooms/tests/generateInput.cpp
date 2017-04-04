#include <random>
#include <chrono>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 g1 (seed1);  // mt19937 is a standard mersenne_twister_engine
    std::uniform_int_distribution<int> distDown(0, numeric_limits<int>::max() >> 1);
    std::uniform_int_distribution<int> distUpp((numeric_limits<int>::max() >> 1) + 1, numeric_limits<int>::max());

    cout << "100000\n";
    for (int i = 100000; i; --i) {
        cout << distDown(g1) << ' ' << distUpp(g1) << '\n';
    }

    return 0;

}
