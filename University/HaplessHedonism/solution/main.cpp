#include <iostream>



int main() {
    unsigned long long int dp[1000001];
    
    dp[0] = dp[1] = dp[2] = dp[3] = 0;
    dp[4] = 1;
    for (unsigned long long int i = 5; i <= 1000000; ++i) {
        unsigned long long int m = i >> 1;
        dp[i] = dp[i - 1] + m * (m - 1);

        if ((i & 1) == 0) {
          dp[i] -= m - 1;
        }
    }

    int t, x;

    for (std::cin >> t; t; --t) {
        std::cin >> x;
        std::cout << dp[x] << '\n';
    }


    return 0;



}
