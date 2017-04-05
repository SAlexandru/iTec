#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cassert>


using namespace std;

vector<int> v;
vector<int> sol;

//from [left, right)
void bitonic_search(const int& x, int left, int right) {
    if (left >= right) return; //no element sequence
    else if (left + 1 == right) { //one element sequence
        if (v[left] == x) sol.push_back(left);
        return ;
    }
    else if (left + 2 == right) { //two element sequence
        if (v[left] == x) sol.push_back(left);
        if (v[left + 1] == x) sol.push_back(left + 1);
        return;
    }

    for (int i = left; i < right; ++i) {
        if (v[i] == x) sol.push_back(i);
    }
}

void is_bitonic(const vector<int>& v) {
    assert(v.size() <= 100000);
    assert(v.size() >= 3);

    int pivot = 0;
    for (int i = 1; i + 1 < v.size(); ++i) {
        if (v[i - 1] < v[i] && v[i] > v[i + 1]) {
          pivot = i;
          break;
        }
    }

    //cout << "Pivot Index at: " << pivot << '\n'; cout.flush();
    

    for (int i = 1; i < pivot; ++i) {
       if (v[i - 1] >= v[i]) {
           cout << "Wrong numbers at position " << i << " " << v[i - 1] << " should be < " << v[i] << "\n";
           cout.flush();
       }
       assert(v[i - 1] < v[i]);
    }

    for (int i = pivot + 1; i < v.size(); ++i) {
       if (v[i - 1] <= v[i]) {
           cout << "Wrong numbers at position " << i << " " << v[i - 1] << " should be > " << v[i] << "\n";
           cout.flush();
       }

        assert(v[i] < v[i - 1]);
    }
}

int main() {
    int N, T, x;

    cin >> N;
    while(N--) {
        cin >> x;
        v.push_back(x);
    }

    is_bitonic(v);

    cin >> T;
    assert(T >= 1);
    assert(T <= 1000);
    while (T--) {
        cin >> x;
        bitonic_search(x, 0, v.size());
        if (sol.empty()) cout << "Number Not Found";
        else {
            copy(sol.begin(), sol.end(), ostream_iterator<int>{cout, " "});
            sol.clear();
        }

        cout << '\n';
    }

    return 0;
}
