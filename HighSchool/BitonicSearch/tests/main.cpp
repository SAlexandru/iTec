#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <functional>
#include <cassert>


using namespace std;

vector<int> v;
vector<int> sol;

void bsearch(const int& x, int left, int right, const function<bool(int, int)>& cmp = less<int>()) {
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

    int middle = left + ((right - left) >> 1);


    if (v[middle] == x) {
        sol.push_back(middle);
        return;
    }
    else if (cmp(x, v[middle])) bsearch(x, left, middle, cmp);
    else bsearch(x, middle + 1, right, cmp);
}

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

    int middle = left + ((right - left) >> 1);

    if (v[middle] == x) sol.push_back(middle);

    //we have at least 3 elements in the sequence
    if (v[middle - 1] < v[middle] && v[middle] < v[middle + 1]) {
        //asc sequence from [left, middle + 1]
        if (x < v[middle]) {
            bsearch(x, left, middle);
            bitonic_search(x, middle + 1, right);
        }
        else bitonic_search(x, middle + 1, right);
    }
    else if (v[middle - 1] > v[middle] && v[middle] > v[middle + 1]) {
        //desc sequence from [middle, right)
        if (x < v[middle])  {
            bsearch(x, middle + 1, right, greater<int>());
            bitonic_search(x, left, middle);
        }
        else bitonic_search(x, left, middle);
    }
    else { //middle is the pivot
        bsearch(x, left, middle);
        bsearch(x, middle + 1, right, greater<int>());
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
