#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> sol;

void bitonic_search(const int& x) {
    for (size_t i = 0; i < v.size(); ++i) {
        if (v[i] == x) sol.push_back(i);
    }
}

int main() {
    int N, x;

    cin >> N >> x;
    v.reserve(N);
    copy(istream_iterator<int>{cin}, istream_iterator<int>{}, back_inserter(v));

    bitonic_search(x);
    
    if (sol.empty()) {
        cout << "Number not found\n";
    }
    else {
        copy(sol.begin(), sol.end(), ostream_iterator<int>{cout, " "});
        cout << "\n";
    }

    return 0;
}
