#include <iostream>
 
using namespace std;
 
int msb(int x) {return 8*sizeof(int) - __builtin_clz(x) - 1; }
int max(int x, int y) {return x > y ? x : y;}
 
bool equal(int x, int pos) {return ((1 << pos) & x) != 0;}

int lca2(int x, int y) {
    if (x == y) return x;
   
    int idx = msb(x ^ y);

    int diff = 1 << idx;
    int ans = (x & ~(diff - 1)) | diff;

    return ans & ~1;
}
 
int lca(int x, int y) {
    if (msb(x) != msb(y)) {
      return 1 << max(msb(x), msb(y));
    }
 
    int sol = 0;
 
    for (int b = msb(x); b >= 0; --b) {
        if (((1 << b) & x) == ((1 << b) & y)) {
           sol |= (1<<b) & x;
        }
        else if (b != 0) {
           return sol | (1 << b);
        }
    }
 
    return sol;
}
 
int main() {
    /*
    for (int i = 15; i >= 1; --i) {
        for (int j = 1; j <= i; ++j) {
            cout << i << ' ' << j << ' ' << lca(i, j) << ' ' << lca2(i, j) << '\n';
        }
    }
    */
    for (int x, y; cin >> x >> y;) {
        cout << lca2(x, y) << "\n";
    }
 
    return 0;
}
