#include <iostream>
 
using namespace std;
 
int msb(int x) {return 8*sizeof(int) - __builtin_clz(x) - 1; }
int lsb(int x) {return __builtin_ctz(x); }

int max(int x, int y) {return x > y ? x : y;}
 
bool equal(int x, int pos) {return ((1 << pos) & x) != 0;}

int lca(int x, int y) {
    if (x == y) return x;
   
    int idx = msb(x ^ y);
    int lsbIdx = max(lsb(x), lsb(y));

    int diff = 1 << idx;
    return ((x & ~(diff - 1)) | diff) & ~((1 << (lsbIdx)) - 1);
}
 
int main() {
    for (int x, y; cin >> x >> y; ) {
        cout << lca(x, y) << ' ';
    }

    return 0;
}


