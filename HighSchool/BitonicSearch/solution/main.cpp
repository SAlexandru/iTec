#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> sol;

void search_desc(const int& x, const int& left, const int& right) {
    if (left >= right) return;

    int middle = left + ((right - left) >> 1);

    if (v[middle] == x) {
        sol.push_back(middle);
    }
    else if (x < v[middle]) {
        search_desc(x, middle + 1, right);
    }
    else search_desc(x, left, middle);
}

void search_asec(const int& x, const int& left, const int& right) {
    if (left >= right) return;

    int middle = left + ((right - left) >> 1);

    if (v[middle] == x) {
        sol.push_back(middle);
    }
    else if (x > v[middle]) {
        search_asec(x, middle + 1, right);
    }
    else search_asec(x, left, middle);
}

void bitonic_search(const int& x, const int& left, const int& right) {
    if (left >= right) return;

    int middle = left + ((right - left) >> 1);

    if (v[middle] == x) {
        sol.push_back(middle);
    }

    if (left + 1 == middle) return ;

    if (v[middle] > v[middle - 1]) {
        if (x > v[middle]) {
            bitonic_search(x, middle + 1, right);
        }
        else {
            search_asec(x, left, middle);
            search_desc(x, middle + 1, right);
        }
    }
    else if (x > v[middle]) {
        bitonic_search(x, left, middle);
    }
    else {
        search_asec(x, left, middle);
        search_desc(x, middle + 1, right);
    }
}

int main() {
    int N, T, x;

    cin >> N;
    v.reserve(N);
    copy(istream_iterator<int>{cin}, istream_iterator<int>{}, back_inserter(v));

    for (cin >> T; T; --T) {
       bitonic_search(x, 0, v.size());
        
       if (sol.empty()) cout << "Number not found\n";
       else {
         copy(sol.begin(), sol.end(), ostream_iterator<int>{cout, " "});
         cout << "\n";
       }

       sol.clear();
    }

    return 0;
}
