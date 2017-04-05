#include <iostream>

using namespace std;

int main() {
    unsigned long long int dp[1000011];

    dp[3] = 0;
    dp[4] = 1;
    for (int i = 5; i <= 1000000; ++i) {
        int m = i >> 1;
        dp[i] = dp[i - 1] + m * (m - 1);

        if (!(i & 1)) {
           dp[i] -= m - 1; 
        }
    }
    
    int x;
    cin >> x;
    while (cin >> x) {
        cout << dp[x] << '\n';
    }

    return 0;
}
