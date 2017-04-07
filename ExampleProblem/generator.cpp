#include <map>
#include <set>
#include <queue>
#include <vector>
#include <random>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>


using namespace std;

random_device rd;
mt19937 gen(rd());

int main() {
    ofstream outIn {"input.in"};
    ofstream outOk {"output.ok"};

    for (int i = 0; i < 50000; ++i) {
        int a = gen(), b = gen();

        outIn << a << ' ' << b << '\n';
        outOk << (a * 1LL + b) << '\n';
    }

    return 0;
}
