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
uniform_int_distribution<> NRand(50, 100), MRand(100, 50 * 99);

void test1() { //circle
    cout << " --- start test 1 --- \n";
    ofstream out {"input1.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 1 --- \n";

    out.close();

}

int main() {
    test1();
    /*
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    */

    return 0;
}
