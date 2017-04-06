#include <stdio.h>

int getLevel(long a) {
    if(a == 0 || a % 2==1) return 0;
    return 1 + getLevel(a/2);
}

int getParent(long a) {
    long acc = 1;
    if(a==0) return 0;
    int a1 = a;
    // Gasim primul bit de 1 si in acelasi timp cea-mai-semnificativa putere a lui 2
    while(a1%2 != 1) {
        a1/=2;
        acc *= 2;
    }
    // Pentru a ajunge din nod la parintele sau, daca numarul se termina in 01, trebuie sa adunam cea-mai-semnificativa-putere-a-lui-2;
    // Daca se termina in 11, trebuie sa
    if((a1 >> 1) %2 == 0)
        return a + acc;
    else return a - acc;
}

void solveProblem() {
   int n, a, b, aux, it;
   scanf("%d", &n);

   while(n > 0) {
        scanf("%ld %ld", &a, &b);
        int lvlA = getLevel(a);
        int lvlB = getLevel(b);
        if(lvlB < lvlA) {
            aux = a;
            a=b;
            b=aux;
            aux = lvlA;
            lvlA=lvlB;
            lvlB=aux;
        }
        for (int i=0;i<(lvlB-lvlA);i++) {a=getParent(a);}
        while(a!=b) {
            a=getParent(a);
            b=getParent(b);
        }
        printf("%ld\n",a);
        n--;
    }
}
/*
int main()
{
    char* in[] =  {"1.in", "2.in", "3.in", "4.in", "5.in", "6.in", "7.in", "8.in", "9.in", "10.in"};
    char* out[] = {"1.ot", "2.ot", "3.ot", "4.ot", "5.ot", "6.ot", "7.ot", "8.ot", "9.ot", "10.ot"};

    for (int i=0;i<10;i++) {
        freopen(in[i], "r",stdin);
        freopen(out[i],"w",stdout);
        solveProblem();
    }

    return 0;
}


*/
