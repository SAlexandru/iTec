#include <stdio.h>

long a[1000002]; // Array-ul in care construim dinamic solutia

void solve() {
    long it, t, n;
    scanf("%d", &t);
    for(int it=0; it<t; it++) {
        scanf("%ld", &n);
        printf("%ld\n", a[n]);
    }
}

int main(){
    a[1]=0;a[2]=0;a[3]=0;a[4]=1; // Cazurrile de pornire
    for (long i=5; i <= 1000000; i++) {
        a[i] = a[i-1];
        long numberOfNewTriangles = (i/2-2)*(i/2-1);
        if(i%2==0) numberOfNewTriangles += (i/2 - 1);
        else numberOfNewTriangles += 2 * (i/2-1);
        a[i] += numberOfNewTriangles;
        if(i %1000 == 0) {
           // printf("%ld:: %ld\n", i, a[i]);
        }
    }


    char* in[] =  {"1.in", "2.in", "3.in", "4.in", "5.in", "6.in", "7.in", "8.in", "9.in", "10.in"};
    char* out[] = {"1.ot", "2.ot", "3.ot", "4.ot", "5.ot", "6.ot", "7.ot", "8.ot", "9.ot", "10.ot"};
    for (int i=0;i<10;i++) {
        freopen(in[i], "r",stdin);
        freopen(out[i],"w",stdout);
        solve();
    }
    return 0;
}

