#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


void addNumber(char* accumulator, int* index, int number) {
    if(number == 0) return;
    else {
        addNumber(accumulator, index, number/10);
        accumulator[*index] = (number%10) + '0';
        (*index)++;
    }
}

void addRandomVariableOrNoVar(char* accumulator, int* index) {
    int variableOption = rand()%3;

    int nr = rand()%20;
    if(nr >= 10) nr = rand()%200;
    if(nr >= 100) nr = rand()%1001;
    if(variableOption == 0 || (nr !=1)) addNumber(accumulator, index, nr);

    if(variableOption == 0 && nr != 0) return;
    else if (variableOption == 1){ accumulator[*index] = 'x'; (*index)++;}
    else { accumulator[*index] = 'y'; (*index)++;}
}

void addRandomSign(char* accumulator, int* index) {
    int option = rand()%2;
    if(option == 0) { accumulator[*index] = '+'; (*index)++;}
    else if (option == 1){ accumulator[*index] = '-'; (*index)++;}
}

void addEqSign(char* accumulator, int* index) {
    accumulator[*index] = '='; (*index)++;
}



char* generate_equation(int nrTerms) {
    char* ans = (char*)malloc(nrTerms * 100);
    int nrTermsE1 = nrTerms + 3 * (rand()%nrTerms + rand()%nrTerms + rand()%nrTerms + rand()%nrTerms);
    int nrTermsE2 = nrTerms + 3 * (rand()%nrTerms + rand()%nrTerms + rand()%nrTerms + rand()%nrTerms);

    int c=0;
    for (int i=0; i < nrTermsE1; i++) {
        addRandomVariableOrNoVar(ans, &c);
        if (i != (nrTermsE1-1)) {
            addRandomSign(ans, &c);
        } else addEqSign(ans, &c);
    }
    for (int i=0; i < nrTermsE2; i++) {
        addRandomVariableOrNoVar(ans, &c);
        if (i != (nrTermsE2-1)) {
            addRandomSign(ans, &c);
        }
    }
    return ans;
}

int main()
{

    char* ar[] = {"3.in", "4.in", "5.in", "6.in", "7.in", "8.in", "9.in", "10.in"};
    srand (time(NULL));
    for (int i = 0; i < 8; i++){
        freopen(ar[i],"w",stdout);
        int n = i + 3;
        printf("%d\n", n);
        for (int j=0; j < n; j++) {
            char* equation = generate_equation(n);
            printf("%s\n", equation);
        }
    }
    return 0;
}
