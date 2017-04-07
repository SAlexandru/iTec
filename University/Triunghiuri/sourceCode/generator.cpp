#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void doGenerate(int testCount) {
    int nrT = testCount * testCount;
    cout << nrT << "\n";
    for (int i=0;i< nrT;i++) {
        if(testCount <=3)
            cout << rand() % 10 + 4 << "\n";
        else if(testCount <=7)
            cout << rand() % 1000 + 4 << "\n";
        else cout << rand() % 999997 + 4 << "\n";
    }


}
/*
int main(){


    char* out[] =  {"1.in", "2.in", "3.in", "4.in", "5.in", "6.in", "7.in", "8.in", "9.in", "10.in"};
    srand (time(NULL));

    for (int i=0;i<10;i++) {
        freopen(out[i],"w",stdout);
        doGenerate(i+1);
    }
    return 0;
}
*/
