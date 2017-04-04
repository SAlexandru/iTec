#include <set>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 gen (seed1);  // mt19937 is a standard mersenne_twister_engine
uniform_int_distribution<> NRand(50000, 100000);
uniform_int_distribution<> numbers(- 1000000000, 1000000000);

void test1() {
    ofstream out{"input1.in"};

    for (int i = 0; i < 5; ++i) out << i << '\n';


    out.close();
}

void test2() {
    ofstream out{"input2.in"};

    for (int i = 0; i < 15; ++i) out << i << '\n';

    out.close();
}

void test3() {
    cout << "--- start test 3 -----\n"; cout.flush();

    ofstream out{"input3.in"};

    for (int i = 0; i < 35; ++i) out << i << '\n';

    cout << "--- stop test 3 -----\n";

    out.close();
}

void test4() {
    cout << "--- start test 4 -----\n"; cout.flush();

    ofstream out{"input4.in"};

    for (int i = 0; i < 45; ++i) out << i << '\n';

    cout << "--- stop test 3 -----\n";

    out.close();
}

void test5() {
    cout << "--- start test 5 -----\n"; cout.flush();

    ofstream out{"input5.in"};

    for (int i = 0; i < 55; ++i) out << i << '\n';

    cout << "--- stop test 5 -----\n";

    out.close();
}

void test6() {
    cout << "--- start test 6 -----\n"; cout.flush();

    ofstream out{"input6.in"};

    for (int i = 0; i < 65; ++i) out << i << '\n';

    cout << "--- stop test 6 -----\n";

    out.close();
}

void test7() {
    cout << "--- start test 7 -----\n"; cout.flush();

    ofstream out{"input7.in"};

    vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i % 77);
    }

    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) out << v[i] << '\n';
    out << '\n';

    cout << "--- stop test 7 -----\n";

    out.close();
}

void test8() {
    cout << "--- start test 8 -----\n"; cout.flush();

    ofstream out{"input8.in"};

    vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i % 77);
    }

    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) out << v[i] << '\n';
    out << '\n';

    cout << "--- stop test 8 -----\n";

    out.close();
}

void test9() {
    cout << "--- start test 9 -----\n"; cout.flush();

    ofstream out{"input9.in"};

    vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i % 77);
    }

    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) out << v[i] << '\n';
    out << '\n';

    cout << "--- stop test 9 -----\n";

    out.close();
}

void test10() {
    cout << "--- start test 10 -----\n"; cout.flush();

    ofstream out{"input10.in"};

    vector<int> v;
    for (int i = 0; i < 100000; ++i) {
        v.push_back(i % 77);
    }

    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < v.size(); ++i) out << v[i] << '\n';
    out << '\n';

    cout << "--- stop test 10 -----\n";

    out.close();
}


int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;

}
