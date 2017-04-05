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

void test2() { //circle
    cout << " --- start test 2 --- \n";
    ofstream out {"input2.in"};
    vector<string> v;

    out << "20 171\n";
    out << "ana\nbna\nbma\nama\nana\n"; //5
    out << "anc\nanna\nannc\n"; // 3
    out << "ford\nfork\nfoak\nfooak\nfooad\nforad\n"; // 6
    out << "fopak\nfopk\nfoopk\n"; // 3
    out << "zzz\nzxz\nzyz\n"; // 3
    out << "vwt\nvwv\nvvv\n"; // 3 
    out << "beric\n"; // 1

    v.push_back("ana");
    v.push_back("bna");
    v.push_back("bma");
    v.push_back("ama");
    v.push_back("ana");
    v.push_back("anc");
    v.push_back("anna");
    v.push_back("annc");
    v.push_back("ford");
    v.push_back("fork");
    v.push_back("foak");
    v.push_back("fooak");
    v.push_back("fooad");
    v.push_back("forad"); 
    v.push_back("fopak");
    v.push_back("fopk");
    v.push_back("foopk"); 
    v.push_back("zzz");
    v.push_back("zxz");
    v.push_back("zyz"); 
    v.push_back("vwt");
    v.push_back("vwv");
    v.push_back("vvv");  
    v.push_back("beric"); 

    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t j = i + 1; j < v.size(); ++j) {
            out << v[i] << ' ' << v[j] << '\n';
        }
    }

    cout << " --- stop test 2 --- \n";

    out.close();
}

void test3() { //circle
    cout << " --- start test 3 --- \n";
    ofstream out {"input3.in"};


    cout << " --- stop test 3 --- \n";

    out.close();
}

void test4() { //circle
    cout << " --- start test 4 --- \n";
    ofstream out {"input4.in"};


    cout << " --- stop test 4 --- \n";

    out.close();
}

void test5() { //circle
    cout << " --- start test 5 --- \n";
    ofstream out {"input5.in"};

    cout << " --- stop test 5 --- \n";

    out.close();
}

void test6() { //circle
    cout << " --- start test 6 --- \n";
    ofstream out {"input6.in"};


    cout << " --- stop test 6 --- \n";

    out.close();
}

void test7() { //circle
    cout << " --- start test 7 --- \n";
    ofstream out {"input7.in"};

    cout << " --- stop test 7 --- \n";

    out.close();
}

void test8() { //circle
    cout << " --- start test 8 --- \n";
    ofstream out {"input8.in"};

    cout << " --- stop test 8 --- \n";

    out.close();
}

void test9() { //circle
    cout << " --- start test 9 --- \n";
    ofstream out {"input9.in"};

    cout << " --- stop test 9 --- \n";

    out.close();
}

void test10() { //circle
    cout << " --- start test 10 --- \n";
    ofstream out {"input10.in"};

    cout << " --- stop test 10 --- \n";

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
