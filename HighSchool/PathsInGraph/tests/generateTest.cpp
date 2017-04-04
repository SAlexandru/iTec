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

void printTo(const string& filename, const vector<pair<int, int>>& v) {
    ofstream out{filename + ".dot"};

    out << "strict graph {\n";
    for (const auto& x: v) {
        out << x.first << " -- " << x.second << "\n";
    }

    out << "}\n";

    out.close();
}

void test1() { //circle
    ofstream out {"input1.in"};

    out << "5 5 1\n";
    out << "1 2\n";
    out << "2 3\n";
    out << "3 4\n";
    out << "4 5\n";
    out << "5 1\n";

    out.close();

    printTo("graph1", {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 1}});
}

void test2() { //tree
    ofstream out {"input2.in"};

    out << "10 9 1\n";
    out << "1 2\n";
    out << "1 3\n";
    out << "3 4\n";
    out << "3 5\n";
    out << "2 6\n";
    out << "2 7\n";
    out << "7 8\n";
    out << "6 9\n";
    out << "3 10\n";

    out.close();
    printTo("graph2", {{1, 2}, {2, 3}, {3, 4}, {3, 5}, {2, 6}, {2, 7}, {7, 8}, {6, 9}, {3, 10}});
}

void test3() { //complete graph
    cout << "---- start test 3 -----\n"; cout.flush();
    ofstream out{"input3.in"};

    vector<pair<int, int>> v;
    out << "15 " << (15 * 7) << " 3\n";
    for (int i = 1; i <= 15; ++i) {
        for (int j = i + 1; j <= 15; ++j) {
            v.emplace_back(i, j);
            out << j << " " << i << "\n";
        }
    }
    printTo("graph3", v);
    cout << "---- stop test 3 -----\n"; cout.flush();

}

void test4() { // fully random
    cout << "---- start test 4 -----\n"; cout.flush();

    ofstream out{"input4.in"};

    int N = NRand(gen);
    int M = MRand(gen);
    vector<pair<int, int>> v;
    uniform_int_distribution<> nodesRand(1, N);

    out << N << " " << M << " " << nodesRand(gen) << "\n";
    while (M--) {
        int x = nodesRand(gen), y;

        do { y = nodesRand(gen); } while (x == y);

        v.emplace_back(x, y);

        out << x << " " << y << "\n";

    }

    out.close();

    printTo("graph4", v);
    cout << "---- stop test 4 -----\n"; cout.flush();
}

void test5() { // parly random
    cout << "---- start test 5 -----\n"; cout.flush();
   
    ofstream out{"input5.in"};

    int N = 100;
    int M = 55 * 99;
    uniform_int_distribution<> nodesRand(1, N);
    vector<pair<int, int>> v;

    out << N << " " << M << " " << nodesRand(gen) << "\n";
    while (M--) {
        int x = nodesRand(gen), y;

        do { y = nodesRand(gen); } while (x == y);

        v.emplace_back(x, y);

        out << x << " " << y << "\n";

    }

    out.close();

    printTo("graph5", v);

    cout << "---- start test 5 -----\n"; cout.flush();
}

void test6() { //Lollipop Graph (50, 50)
    cout << "---- start test 6 -----\n"; cout.flush();
 
    ofstream out {"input6.in"};
    
    vector<pair<int, int>> nodes;

    for (int i = 1; i <= 50; ++i) {
        for (int j = i + 1; j <= 50; ++j) nodes.emplace_back(i, j);
    }

    for (int i = 51; i <= 100; ++i) {
        nodes.emplace_back(i, i - 1);
    }

    out << "100 " << nodes.size() << " 100\n";
    for (const auto& x: nodes) {
        out << x.first << ' ' << x.second << '\n';
    }

    out.close();

    printTo("graph6", nodes);

    cout << "---- stop test 6 -----\n"; cout.flush();
}

void test7() { // 3/4 random
    cout << "---- start test 7 -----\n"; cout.flush();

    ofstream out{"input7.in"};

    int N = max(70, NRand(gen));
    int M = max( (35 * 69) >> 1,  MRand(gen));
    uniform_int_distribution<> nodesRand(1, N);
    vector<pair<int, int>> v;

    out << N << " " << M << " " << nodesRand(gen) << "\n";
    while (M--) {
        int x = nodesRand(gen), y;

        do { y = nodesRand(gen); } while (x == y);

        out << x << " " << y << "\n";

        v.emplace_back(x, y);

    }

    out.close();

    printTo("graph7", v);

    cout << "---- stop test 7 -----\n"; cout.flush();
}

void test8() { // fully connected subgraphs
    cout << "---- start test 8 -----\n"; cout.flush();

    ofstream out{"input8.in"};

    vector<pair<int, int>> v;

    for (int i = 1; i <= 100; i += 10) {
        for (int j = i; j < i + 10; ++j) {
            for (int k = j + 1; k < i + 10; ++k) {
                v.emplace_back(j, k);
            }
        }
    }

    out << "100 " << v.size() << " 41\n";
     for (const auto& x: v) {
        out << x.first << ' ' << x.second << '\n';
    }

    out.close();
    printTo("graph8", v);

    cout << "---- stop test 8 -----\n"; cout.flush();
}

void test9() { //starts
    cout << "---- start test 9 -----\n"; cout.flush();

    ofstream out{"input9.in"};

    vector<pair<int, int>> v;
    for (int i = 1; i <= 97; i += 3) {
        v.emplace_back(i, i + 1);
        v.emplace_back(i + 1, i + 2);
        v.emplace_back(i + 2, i + 3);
        v.emplace_back(i + 3, i);
    }

    out << "100 " << v.size() << " 57\n";
    for (const auto& x: v) {
        out << x.first << ' ' << x.second << '\n';
    }

    out.close();
    printTo("graph9", v);

    cout << "---- stop test 9 -----\n"; cout.flush();
}

void test10() { //bigger stars and connected between them
    cout << "---- start test 10 -----\n"; cout.flush();

    ofstream out{"input10.in"};

    vector<pair<int, int>> v;
    uniform_int_distribution<> s(1, 20);


    for (int i = 1, size = 0; i < 100; i += size) {
        size = min(100 - i, s(gen) + 1);

        for (int j = 1; j <= size; ++j) {
            v.emplace_back(i + j - 1, i + j);
            for (int k = 1; k < j; ++k) {
                v.emplace_back(i + j, i + k);
            }
        }
    }

    out << "100 " << v.size() << " 57\n";
    for (const auto& x: v) {
        out << x.first << ' ' << x.second << '\n';
    }

    out.close();
    printTo("graph10", v);

    cout << "---- stop test 10 -----\n"; cout.flush();
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
