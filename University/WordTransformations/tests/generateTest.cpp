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

    out << " \n";
    out << "ana\nbna\nbma\nama\nana\n";
    out << "anc\nanna\nannc\n";
    out << "ford\nfork\nfoak\nboak\nbook\nbord\n";


    cout << " --- stop test 2 --- \n";

    out.close();
}

void test3() { //circle
    cout << " --- start test 3 --- \n";
    ofstream out {"input3.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 3 --- \n";

    out.close();
}

void test4() { //circle
    cout << " --- start test 4 --- \n";
    ofstream out {"input4.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 4 --- \n";

    out.close();
}

void test5() { //circle
    cout << " --- start test 5 --- \n";
    ofstream out {"input5.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 5 --- \n";

    out.close();
}

void test6() { //circle
    cout << " --- start test 6 --- \n";
    ofstream out {"input6.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 6 --- \n";

    out.close();
}

void test7() { //circle
    cout << " --- start test 7 --- \n";
    ofstream out {"input7.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 7 --- \n";

    out.close();
}

void test8() { //circle
    cout << " --- start test 8 --- \n";
    ofstream out {"input8.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 8 --- \n";

    out.close();
}

void test9() { //circle
    cout << " --- start test 9 --- \n";
    ofstream out {"input9.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

    cout << " --- stop test 9 --- \n";

    out.close();
}

void test10() { //circle
    cout << " --- start test 10 --- \n";
    ofstream out {"input10.in"};

    out << "4 6\n";
    out << "ana\nbna\nbma\nama\n";
    out << "ana bna\n";
    out << "ana ama\n";
    out << "ana bma\n";
    out << "bna bma\n";
    out << "bna ama\n";
    out << "bma ama\n";

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
