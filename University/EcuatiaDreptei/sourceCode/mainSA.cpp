#include <string>
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

bool isDigit(char c) {return c >= '0' && c <= '9';}
bool isVar(char c) {return c == 'x' || c == 'y'; }

void process(const string& ec, int& x, int& y, int& c) {
    size_t i = 0;
    int num = 0;

    for (i = 0; i < ec.size() && isDigit(ec[i]); ++i) {
        num = num * 10 + ec[i] - '0';
    }

    if (i < ec.size()) {
        if (ec[i] == 'x') {x += num ? num : 1; ++i;}
        else if (ec[i] == 'y') {y += num ? num : 1; ++i;}
        else c += num;
    }
    else c += num;

    while (i < ec.size()) {
        int sign = ec[i++] == '+' ? 1 : -1;

        for (num = 0; i < ec.size() && isDigit(ec[i]); ++i) {
            num = num * 10 + ec[i] - '0';
        }

        if (i < ec.size()) {
            if (ec[i] == 'x') {x += num ? num * sign : sign; ++i;}
            else if (ec[i] == 'y') {y += num ? num * sign : sign; ++i;}
            else c += num * sign;
        }
        else c += num * sign;
    }
}

int main() {
    int N; 
    string line;

    cin >> N;
    assert(1 <= N && N <= 10);
    while(N--) {
        cin >> line;
        string ec1, ec2;
        int x = 0, y = 0, c = 0;

        ec1 = line.substr(0, line.find('='));
        ec2 = line.substr(line.find('=') + 1);

        process(ec2, x, y, c);
        x *= -1;
        y *= -1;
        c *= -1;
        process(ec1, x, y, c);

        double ans = trunc((abs(c) / sqrt(x * x + y * y + 0.0)) * 100) / 100.0;

        std::cout.precision(2);
        cout << std::fixed << ans  << "\n";
    }

    return 0;
}
