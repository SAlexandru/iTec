#include <set>
#include <stack>
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <limits>

namespace std
{
   template <typename T1, typename T2>
   std::ostream& operator<<(std::ostream& strm, const std::pair<T1, T2>& kvPair) {
       strm << kvPair.first << " " << kvPair.second;
       return strm;
   }
}

using namespace std;

unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937 gen (seed1);  // mt19937 is a standard mersenne_twister_engine
std::uniform_int_distribution<int> allGen(0, numeric_limits<int>::max());
std::uniform_int_distribution<int> distDown(0, numeric_limits<int>::max() >> 1);
std::uniform_int_distribution<int> distUpp((numeric_limits<int>::max() >> 1) + 1, numeric_limits<int>::max());

int min(int x, int y) {return x < y ? x : y;}

void test1() {
    cout << "--- start test 1 ---\n";

    ofstream out {"input1.in"};

    out << "7\n";
    out << "-10 10\n5 7\n1 2\n2 3\n2 7\n9 10\n-10 2\n";

    cout << "--- stop test 1\n";

    out.close();
}

void test2() {
    cout << "--- start test 2 ---\n";

    ofstream out {"input2.in"};

    int N = 100;
    vector<int> numbers;

    out << "100\n";

    for (int count = 0, i = distDown(gen) + 10; count < 100; ++i, ++count) {
        out << i << ' ' << (i + 1) << '\n';
    }

    cout << "--- stop test 2 ---\n";

    out.close();
}

void test3() {
    cout << "--- start test 3 ---\n";

    ofstream out {"input3.in"};

    int N = 10000;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; ++i) {
       v.emplace_back(distDown(gen), distUpp(gen));
    }

    random_shuffle(v.begin(), v.end());

    out << v.size() << '\n';

    cout << "--- stop test 3 ---\n";
    copy(v.begin(), v.end(), ostream_iterator<pair<int, int>>{out, "\n"});

    out.close();
}

void test4() {
    cout << "--- start test 4 ---\n";

    ofstream out {"input4.in"};

    int N = 100000;
    set<int> seq;
    vector<pair<int, int>> v;

    do {
        seq.insert(allGen(gen));
    } while (seq.size() != N);

    vector<int> firstPart, secondPart;

    set<int>::iterator it = seq.begin();
    for (int i = 0; it != seq.end(); ++i, it = next(it, 1)) {
        if (i < 50000) firstPart.push_back(*it);
        else secondPart.push_back(*it);
    }

    random_shuffle(secondPart.begin(), secondPart.end());

    out << "50000\n";

    for (int i = 0; i < 50000; ++i) {
       out << firstPart[i] << ' ' << secondPart[i] << '\n';
    }


    cout << "--- stop test 4 ---\n";

    out.close();
}

void test5() {
    cout << "--- start test 5 ---\n";

    ofstream out {"input5.in"};

    int N = 75000;
    int numOfIndep = 10;
    int numOfContainers = 100; // random between 10 -- 100
    std::uniform_int_distribution<int> numOfIGen(1, numOfIndep);
    std::uniform_int_distribution<int> numOfCGen(10, numOfContainers);


    vector<pair<int, int>> v;

    for (int count = 0, i = std::numeric_limits<int>::min(); count < 75000; ) {
        int n = numOfIGen(gen);
        int m = numOfCGen(gen);
        for (int j = 0; j < m; ++j) {
            v.emplace_back(i + j, i + (m - j)  + m + n);
        }
        for (int j = 0; j < n; ++j) {
            v.emplace_back(i + j + m, i + j + m + 1);
        }
        i += 2 * m + n + 1;
        count += m + n;
    }

    out << v.size() << '\n';
    
    random_shuffle(v.begin(), v.end());
    copy(v.begin(), v.end(), ostream_iterator<pair<int, int>>{out, "\n"});

    cout << "--- stop test 5 ---\n";

    out.close();
}

void test6() {
    cout << "--- start test 6 ---\n";

    ofstream out {"input6.in"};

    int N = 100000;
    int numOfIndep = 20;
    int numOfContainers = 500; // random between 10 -- 100
    std::uniform_int_distribution<int> numOfIGen(5, numOfIndep);
    std::uniform_int_distribution<int> numOfCGen(100, numOfContainers);


    vector<pair<int, int>> v;

    for (int count = 0, i = std::numeric_limits<int>::min(); count < N; ) {
        int n = numOfIGen(gen);
        int m = numOfCGen(gen);
        for (int j = 0; j < m; ++j) {
            v.emplace_back(i + j, i + (m - j)  + m + n);
        }
        for (int j = 0; j < n; ++j) {
            v.emplace_back(i + j + m, i + j + m + 1);
        }
        i += 2 * m + n + 1;
        count += m + n;
    }

    out << min(N, v.size()) << '\n';
    
    random_shuffle(v.begin(), v.end());
    copy(v.begin(), v.begin() + N, ostream_iterator<pair<int, int>>{out, "\n"});

    cout << "--- stop test 6 ---\n";

    out.close();
}

void test7() {
    cout << "--- start test 7 ---\n";

    ofstream out {"input7.in"};

    int N = 200000;
    set<int> seq;
    vector<pair<int, int>> v;

    do {
        seq.insert(allGen(gen));
    } while (seq.size() != N);

    vector<int> firstPart, secondPart;

    set<int>::iterator it = seq.begin();
    for (int i = 0; it != seq.end(); ++i, it = next(it, 1)) {
        if (i < 100000) firstPart.push_back(*it);
        else secondPart.push_back(*it);
    }

    random_shuffle(secondPart.begin(), secondPart.end());

    out << "100000\n";

    for (int i = 0; i < 100000; ++i) {
       out << firstPart[i] << ' ' << secondPart[i] << '\n';
    }


    cout << "--- stop test 7 ---\n";

    out.close();
}

void test8() {
    cout << "--- start test 8 ---\n";

    ofstream out {"input8.in"};

    int N = 100000;
    vector<pair<int, int>> v;

    for (int i = 0; i < N; ++i) {
       v.emplace_back(distDown(gen), distUpp(gen));
    }

    random_shuffle(v.begin(), v.end());

    out << min(N, v.size()) << '\n';

    copy(v.begin(), v.begin() + N, ostream_iterator<pair<int, int>>{out, "\n"});

   cout << "--- stop test 8 ---\n";

    out.close();
}

void test9() {
    cout << "--- start test 9 ---\n";

    ofstream out {"input9.in"};

    int N = 100000;
    int numOfIndep = 20;
    int numOfContainers = 500; // random between 10 -- 100
    std::uniform_int_distribution<int> numOfIGen(5, numOfIndep);
    std::uniform_int_distribution<int> numOfCGen(100, numOfContainers);
    std::uniform_int_distribution<int> numOfIGen2(0, 100);


    vector<pair<int, int>> v;

    for (int count = 0, num = 0; count < N; ) {
       stack<int> numbers;
       int n = numOfIGen(gen);
       int m = numOfCGen(gen);
 
       for (int j = 0; j < m; ++j) {
           numbers.push(num);
           num += 1;
            
           int n2 = numOfIGen2(gen);

           if (n2) {
             for (int k = 0; k < n2; ++k) {
                v.emplace_back(num, num + 1);
                num += 1; //next number
             }
             count += n2;
           }
       }

       for (int j = 0; j < n; ++j) {
           v.emplace_back(num, num + 1);
           num += 1;
       }

       while (!numbers.empty()) {
           int t = numbers.top(); numbers.pop();
           v.emplace_back(t, num);
           num += 1;
           int n2 = numOfIGen2(gen);

           if (n2) {
             for (int k = 0; k < n2; ++k) {
                v.emplace_back(num, num + 1);
                num += 1; //next number
             }
             count += n2;
           }

       }

       count += m + n;
    }


    out << min(N, v.size()) << '\n';
    
    random_shuffle(v.begin(), v.end());
    copy(v.begin(), v.begin() + N, ostream_iterator<pair<int, int>>{out, "\n"});

    cout << "--- stop test 9 ---\n";

    out.close();
}

void test10() {
    cout << "--- start test 10 ---\n";

    ofstream out {"input10.in"};

    int N = 100000;
    int numOfIndep = 50;
    int numOfContainers = 1000; // random between 10 -- 100
    std::uniform_int_distribution<int> numOfIGen(5, numOfIndep);
    std::uniform_int_distribution<int> numOfCGen(100, numOfContainers);
    std::uniform_int_distribution<int> numOfIGen2(0, 500);




    vector<pair<int, int>> v;


    for (int count = 0, num = 0; count < N; ) {
       stack<int> numbers;
       int n = numOfIGen(gen);
       int m = numOfCGen(gen);
 
       for (int j = 0; j < m; ++j) {
           numbers.push(num);
           num += 1;
            
           int n2 = numOfIGen2(gen);

           if (n2) {
             for (int k = 0; k < n2; ++k) {
                v.emplace_back(num, num + 1);
                num += 1; //next number
             }
             count += n2;
           }
       }

       for (int j = 0; j < n; ++j) {
           v.emplace_back(num, num + 1);
           num += 1;
       }

       while (!numbers.empty()) {
           int t = numbers.top(); numbers.pop();
           v.emplace_back(t, num);
           num += 1;
           int n2 = numOfIGen2(gen);

           if (n2) {
             for (int k = 0; k < n2; ++k) {
                v.emplace_back(num, num + 1);
                num += 1; //next number
             }
             count += n2;
           }

       }

       count += m + n;
    }


    out << min(N, v.size()) << '\n';
    
    random_shuffle(v.begin(), v.end());
    copy(v.begin(), v.begin() + N, ostream_iterator<pair<int, int>>{out, "\n"});

    cout << "--- stop test 10 ---\n";

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



