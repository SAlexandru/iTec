#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> v;
vector<int> sol;

void bitonic_search(const int& x) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == x) sol.push_back(i);
    }
}

int main() {
    int N, T, x;

    cin >> N ;
    assert(3 <= N && N <= 100000);

    v.reserve(N);
    copy(istream_iterator<int>{cin}, istream_iterator<int>{}, back_inserter(v));

    int pivot = 0;
    for (int i = 1; i < N - 1; ++i) {
        if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
            pivot = i;
            break;
        }
    }

    for (cin >> T; T; --T) {
       cin >> x;
       bitonic_search(x);

       assert(sol.size() <= 2);

       if (2 == sol.size()) {
         assert( (sol[0] < pivot && sol[1] > pivot) || (sol[0] > pivot && sol[1] < pivot));
       }

       if (sol.empty())  cout << "Number not found\n";
       else {
         copy(sol.begin(), sol.end(), ostream_iterator<int>{cout, " "});
         cout << "\n";
       }

       sol.clear();
    }

    return 0;
}
