#include <stdio.h>

int a[100][3];
int last = 3;
int n = 0;

void solveProblem() {
    while(scanf("%d",&n)!= EOF) {

		for (int i = last + 1; i <=n; i++) {
		  	//if(a[i][0] == 0) {
			  a[i][0] = a[i-1][2];
			  a[i][1] = a[i-1][0] + a[i-1][2];
			  a[i][2] = a[i-1][1];
			//}
		}
        if (n > last) last = n;
		printf ("%d\n", (a[n][1] + a[n][2]));
	}
}

int main() {
    int n;
    int current0, current1, current2;
    a[1][0] = 0;
    a[1][1] = 1;
    a[1][2] = 0;
    a[2][0] = 1;
    a[2][1] = 1;
    a[2][2] = 1;
    a[3][0] = 1;
    a[3][1] = 1;
    a[3][2] = 1;
    last = 3;

	char* in[] =  {"input1.in", "input2.in", "input3.in", "input4.in", "input5.in", "input6.in", "input7.in", "input8.in", "input9.in", "input10.in"};
    char* out[] = {"1.ot", "2.ot", "3.ot", "4.ot", "5.ot", "6.ot", "7.ot", "8.ot", "9.ot", "10.ot"};
    for (int i=0;i<10;i++) {
        freopen(in[i], "r",stdin);
        freopen(out[i],"w",stdout);
        solveProblem();
    }

	return 0;
}
