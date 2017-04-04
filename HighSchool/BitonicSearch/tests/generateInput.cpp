#include <random>
#include <chrono>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 g1 (seed1);  // mt19937 is a standard mersenne_twister_engine

    vector<int> v;
    for (int i = 0; i < 50000; ++i) v.push_back(i);
    for (int i = 50000 - 2; i >= 0; --i) v.push_back(i);

    cout << v.size() << '\n';
    copy(v.begin(), v.end(), ostream_iterator<int>{cout, " "});
    cout << '\n';

    return 0;

}
