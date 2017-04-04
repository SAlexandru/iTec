#include <iostream>

using namespace std;

int main() {
    int v[77];

    v[1] = 1;
    v[2] = v[3] = 2;
    for (int i = 4; i <= 76; ++i) v[i] = v[i - 2] + v[i - 3];

    for (int x; cin >> x; ) {
        cout << v[x] << "\n";
    }

    return 0;
}
