#include <iostream>
#include <cstdio>

unsigned long long int dp[1000001];

void doSolve(){

    int t, x;

    for (std::cin >> t; t; --t) {
        std::cin >> x;
        std::cout << dp[x] << '\n';
    }
}
/*
int main() {


    dp[0] = dp[1] = dp[2] = dp[3] = 0;
    dp[4] = 1;
    for (unsigned long long int i = 5; i <= 1000000; ++i) {
        unsigned long long int m = i >> 1;
        dp[i] = dp[i - 1] + m * (m - 1);

        if ((i & 1) == 0) {
          dp[i] -= m - 1;
        }
    }


    char* in[] =  {"1.in", "2.in", "3.in", "4.in", "5.in", "6.in", "7.in", "8.in", "9.in", "10.in"};
    char* out[] = {"output1.ot", "output2.ot", "output3.ot", "output4.ot", "output5.ot", "output6.ot", "output7.ot", "output8.ot", "output9.ot", "output10.ot"};
    for (int i=0;i<10;i++) {
        freopen(in[i], "r",stdin);
        freopen(out[i],"w",stdout);
        doSolve();
    }

    return 0;

}
*/
