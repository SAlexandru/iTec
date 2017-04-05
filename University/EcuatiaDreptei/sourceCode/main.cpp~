#include <stdio.h>
#include <math.h>

int isChar(char c) {
    if(c=='x' || c=='y') return 1;
    return 0;
}

int isDigit(char c) {
    if(c>='0' && c<='9') return 1;
    return 0;
}

int isSgn(char c) {
    if(c=='-' || c=='+') return 1;
    return 0;
}

int isEquals(char c) {
    if(c=='=') return 1;
    return 0;
}

int isTerm(char c) {
    if(c=='\0') return 1;
    return 0;
}

double distOrigin(int a, int b, int c) {
    if(c < 0)
        c = -1 * c;
    return (double) c / (sqrt(a * a + b * b));
}

void solveProblem() {
    int n;
    char eq[1001];
    scanf("%d", &n);
    for (int in=0; in<n; in++) {
        scanf("%s", eq);
        int currentSgn=1, currentCoef=0, coefX=0,coefY=0, coefLiber=0, foundEq=0;
        for(int i=0; ; i++) {
            if(isDigit(eq[i])) {
                currentCoef = currentCoef * 10 + (eq[i] - '0');
            }
            else if (isChar(eq[i])) {
                if(currentCoef == 0) {currentCoef = 1;} // daca apare litera neprecedata de coeficient
                currentCoef = currentCoef * currentSgn;
                if(foundEq) {currentCoef = currentCoef * (-1);}
                if(eq[i] == 'x')  coefX += currentCoef;
                else if(eq[i] == 'y') coefY += currentCoef;
                currentCoef = 0;
            }
            else if(isSgn(eq[i]) || isEquals(eq[i]) || isTerm(eq[i])) {
                currentCoef = currentCoef * currentSgn;
                if(foundEq) {currentCoef = currentCoef * (-1);}
                coefLiber += currentCoef;
                if (isEquals(eq[i])) {foundEq=1;currentSgn=1;}
                if (isTerm(eq[i])) break;
                if (eq[i] == '+') currentSgn=1;
                if (eq[i] == '-') currentSgn=-1;
                currentCoef = 0;
            }
        }
        /*printf("%d x ", coefX);
        if(coefY >= 0) printf("+ %d y ", coefY); else printf("%d y ", coefY);
        if(coefLiber >= 0) printf("+ %d = 0\n", coefLiber); else printf("%d = 0 \n", coefLiber);
        */
        double d = distOrigin(coefX, coefY, coefLiber);
        printf("%.2f\n",((trunc(d * 100))/100.0));
    }
}

int main() {
    /*
    char* in[] =  {"1.in", "2.in", "3.in", "4.in", "5.in", "6.in", "7.in", "8.in", "9.in", "10.in"};
    char* out[] = {"1.ot", "2.ot", "3.ot", "4.ot", "5.ot", "6.ot", "7.ot", "8.ot", "9.ot", "10.ot"};
    for (int i=0;i<10;i++) {
        freopen(in[i], "r",stdin);
        freopen(out[i],"w",stdout);
        solveProblem();
    }*/
    solveProblem();
    return 0;
}
