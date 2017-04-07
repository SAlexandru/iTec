#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    char* ar[] = {"2.in", "3.in", "4.in", "5.in", "6.in", "7.in", "8.in", "9.in", "10.in"};
    srand (time(NULL));
    for (int i = 0; i < 9; i++){
        freopen(ar[i],"w",stdout);
        int n = (i + 2);
        n*=n;
        n*=n;
        printf("%d\n", n);
        for (int j=0; j < n; j++) {
            int a = rand() % (1<<(3*(i+2)));
            if(a==0) a=1;
            int b = rand() % (1<<(3*(i+2)));
            if(b==0) b = 1;
            printf("%ld %ld\n", a, b);
        }
    }
    return 0;
}
