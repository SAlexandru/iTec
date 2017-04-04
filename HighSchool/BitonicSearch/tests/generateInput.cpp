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

    out << "10\n";
    out << "1 15 21 7 8 9 1 -1 -2 -3\n";
    out << "11\n";
    out << "1\n15\n21\n7\n8\n9\n1\n-1\n-2\n-3\n-5";

    out.close();
}

void test2() {
    ofstream out{"input2.in"};

    out << "10\n";
    out << "-10 6 18 21 22 50 100 7 8 9\n";
    out << "11\n";
    out << "1\n-10\n6\n18\n21\n22\n50\n100\n7\n8\n9\n";

    out.close();
}

void test3() {
    cout << "--- start test 3 -----\n"; cout.flush();

    ofstream out{"input3.in"};

    out << "500\n";

    set<int> v1;
    set<int, greater<int>> v2;
    
    do {
      v1.insert(numbers(gen));
    } while (v1.size() != 250);
    
    do {
      v2.insert(numbers(gen));
    } while (v2.size() != 249);


    for (const auto& x: v1) {
        out << x << ' ';
    }

    out << (*v1.begin() + *v2.begin() - 1) << ' ';
    for (const auto& x: v2) {
        out << x << ' ';
    }

    out << "\n500\n";
    for (const auto& x: v1) out << x << '\n';
    for (const auto& x: v2) out << x << '\n';
    out << gen() << '\n';

    cout << "--- stop test 3 -----\n";
}

void test4() {
    cout << "--- start test 4 -----\n"; cout.flush();

    ofstream out{"input4.in"};

    out << "500\n";

    set<int> v1;
    set<int, greater<int>> v2;
    
    do {
      v1.insert(numbers(gen));
    } while (v1.size() != 249);
   
    v2.insert(*next(v1.begin(), 50));
    do {
      v2.insert(numbers(gen));
    } while (v2.size() != 248);

    out << (v1.size() + v2.size()) << '\n';

    for (const auto& x: v1) {
        out << x << ' ';
    }

    out << (*v1.begin() + *v2.begin() - 1) << ' ';
    for (const auto& x: v2) {
        out << x << ' ';
    }

    out << "\n" << (v1.size() + v2.size() + 1) << '\n';
    for (const auto& x: v1) out << x << '\n';
    for (const auto& x: v2) out << x << '\n';

    out << gen() << '\n';

    cout << "--- stop test 4 -----\n";
}

void test5() {
    cout << "--- start test 5 -----\n"; cout.flush();

    ofstream out{"input5.in"};

    out << "1000\n";

    set<int> v1;
    set<int, greater<int>> v2;
    
    do {
      v1.insert(numbers(gen));
    } while (v1.size() != 500);
    
    do {
      v2.insert(numbers(gen));
    } while (v2.size() != 499);


    for (const auto& x: v1) {
        out << x << ' ';
    }

    out << (*v1.begin() + *v2.begin() - 1) << ' ';
    for (const auto& x: v2) {
        out << x << ' ';
    }

    out << "\n500\n";
    for (const auto& x: v1) {
        out << x << '\n';
    }
    for (const auto& x: v2) {
        out << x << '\n';
    }
    out << gen() << '\n';

    cout << "--- stop test 5 -----\n";
}

void test6() {
    cout << "--- start test 6 -----\n"; cout.flush();

    ofstream out{"input6.in"};

    int N = NRand(gen);
    int M = N >> 1;

    out << N << endl;

    set<int> v1;
    vector<int> v;
    set<int, greater<int>> v2;
    
    do {
      v1.insert(numbers(gen));
    } while (v1.size() != M);
    
    do {
      v2.insert(numbers(gen));
    } while (v2.size() != M - 1);


    for (const auto& x: v1) {
        out << x << ' ';
        v.push_back(x);
    }

    out << (*v1.begin() + *v2.begin() - 1) << ' ';
    v.push_back(*v1.begin() + *v2.begin() - 1);
    for (const auto& x: v2) {
        out << x << ' ';
        v.push_back(x);
    }

    random_shuffle(v.begin(), v.end());
    out << "\n1000\n";
    for (int i = 0; i < 999; ++i) out << v[i] << '\n';
    out << gen() << '\n';

    cout << "--- stop test 6 -----\n";
}

void test7() {
    cout << "--- start test 7 -----\n"; cout.flush();

    ofstream out{"input7.in"};

    int N = 100000;

    out << N << endl;

    vector<int> v;

    for (int i = 1; i <= 50000; ++i) {
        out << i << ' ';
    }
    for (int i = 49999; i >= 0; --i) {
        out << i << ' ';
    }

    out << "\n1000\n";
    for (int i = 0; i < 500; ++i) out << gen() << '\n';
    for (int i = 0; i < 500; ++i) out << i << '\n';

    cout << "--- stop test 7 -----\n";

    out.close();
}

void test8() {
    cout << "--- start test 8 -----\n"; cout.flush();

    ofstream out{"input8.in"};

    int N = 100000;

    out << N << endl;

    vector<int> v;

    for (int i = 1; i <= 50000; ++i) {
        out << (i + 500000) << ' ';
        v.push_back(i + 500000);
    }
    for (int i = 49999; i >= 0; --i) {
        out << (i - 50000) << ' ';
        v.push_back(i - 500000);
    }

    out << "\n1000\n";
    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < 1000; ++i) out << v[i] << '\n';

    cout << "--- stop test 8 -----\n";
}

void test9() {
    cout << "--- start test 9 -----\n"; cout.flush();

    ofstream out{"input9.in"};

    int N = NRand(gen);
    int M = N >> 1;

    out << N << endl;

    set<int> v1;
    vector<int> v;
    set<int, greater<int>> v2;
    
    do {
      v1.insert(numbers(gen));
    } while (v1.size() != M);
    
    do {
      v2.insert(numbers(gen));
    } while (v2.size() != M - 1);


    for (const auto& x: v1) {
        out << x << ' ';
        v.push_back(x);
    }

    out << (*v1.begin() + *v2.begin() - 1) << ' ';
    v.push_back(*v1.begin() + *v2.begin() - 1);
    for (const auto& x: v2) {
        out << x << ' ';
        v.push_back(x);
    }

    random_shuffle(v.begin(), v.end());
    out << "\n1000\n";
    for (int i = 0; i < 999; ++i) out << v[i] << '\n';
    out << gen() << '\n';

    cout << "--- stop test 9 -----\n";
}

void test10() {
    cout << "--- start test 10 -----\n"; cout.flush();

    ofstream out{"input10.in"};

    int N = NRand(gen);
    int M = N >> 1;

    out << N << endl;

    set<int> v1;
    vector<int> v;
    set<int, greater<int>> v2;
    
    do {
      v1.insert(numbers(gen));
    } while (v1.size() != M);
    
    do {
      v2.insert(numbers(gen));
    } while (v2.size() != M - 1);


    for (const auto& x: v1) {
        out << x << ' ';
        v.push_back(x);
    }

    out << (*v1.begin() + *v2.begin() - 1) << ' ';
    v.push_back(*v1.begin() + *v2.begin() - 1);
    for (const auto& x: v2) {
        out << x << ' ';
        v.push_back(x);
    }

    random_shuffle(v.begin(), v.end());
    out << "\n1000\n";
    for (int i = 0; i < 999; ++i) out << v[i] << '\n';
    out << gen() << '\n';

    cout << "--- stop test 10 -----\n";
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
