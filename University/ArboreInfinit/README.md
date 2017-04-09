## Arbore Infinit

# Regula de generare  

Avand un element 2<sup>k</sup>, pe ramura stanga a acestuia vine elementul 2<sup>k</sup> - 2<sup>k-1</sup> = 2<sup>k-1</sup>, 
iar pe cea dreapta 2<sup>k</sup> + 2<sup>k-1</sup>. 

Pe ramura stanga a 2<sup>k</sup> + 2<sup>k-1</sup> vine 2<sup>k</sup> + 2<sup>k-1</sup> - 2<sup>k-2</sup>, 
iar pe cea dreapta vine 2<sup>k</sup> + 2<sup>k-1</sup> + 2<sup>k-2</sup> s.a.m.d


# Solutia lui Mihai:
Consideram a, b numerele.
Nivelul unui numar se considera prima pozitie care are bitul 1 setat (de la dreapta la stanga). 
Primul pas e sa identificam pe ce nivel se afla fiecare dintre cele 2 numere si sa le aducem pe acelasi nivel 
(transformarea copilului in parinte se face simplu adunand/scazand lsb-ul setat pe 1).   
	Cat timp cele 2 nu coincid, a=a parinte(a); b=parinte(b).
  
# Solutia lui Alex (formula):
```
Basic bit operations:
lsb(a) -- indexul pentru least significat bit (cel mai nesemnificativ bit)
msb(a) -- indexul pentru most significat bit (cel mai semnificativ bit)
~a     -- negare pe biti, biti din are care aveau 0 devin 1 si invers. Ex. a = 7 (00...0111) a = -8 (111...1000) (bitul de semn a fost setat :) )
a | b  -- sau pe biti:  a = 7 (000...0111) b = 8 (000...1000)  a | b = 15 = (000...1111)
a & b  -- and pe biti:  a = 7 (000...0111) b = 8 (000...1000)  a & b = 0
a ^ b  -- [xor](https://en.wikipedia.org/wiki/Exclusive_or) pe biti a = 15 (000...1111) b = 7 (000...0111) a ^ b = 8 (000...1000)
1 << b --  2<sup>b</sup>    (cazul general a << b 2<sup>b</sup> * a)
b >> 1 --  b / 2  (cazul general b >> a:  a / 2<sup>b</sup>)
Numarul (1 << b) - 1 are toti biti de la 0 pana la b - 1 setati 
```
Avem numerele a si b pentru care trebuie sa calculam lca(a, b).
Prima observatie este ca lsb(a), respectiv lsb(b) dau nivelul din arbore pe care se afla a, respectiv b.
Alt lucru de observat, din regula de generare, este faptul ca druml de la radacina la numerele a si b este condificat
in biti setati / nesetati de la dreapta la stanga. Astefl parintele comun a celor doua numere a si b este dat de toti biti 
comuni de la stanga la dreapta. 

De exemplu a = 13 (000..1101) si b = 9 (000..1001)
Cele doua numere nu au decat un bit in comun  000...1000 = 8, dar nu 8 este raspunsul ! Observam ca trebuie sa setam si primul
bit care difera, astfel numarul ar deveni: 000...1100 = 12, astfel am ajuns la raspunul corect. Acest bit trebuie setat 
intrucat el reprezinta poztia unde trebuie facut stanga (i.e desetat acest bit) sau dreapta (setam acest bit) pentru a ajunge
la numere. 
Astefl putem implementa formula:
```cpp
//neat way of finding msb and lsb in C++ when using g++. 
// __builtin_clz and __builtin_ctz are functions that are provided by the g++ and gcc compiler **only** and they return
//the number of leading zeros (clz) / treamings zeros (ctz)

int msb(int x) {return 8*sizeof(int) - __builtin_clz(x) - 1; }
int lsb(int x) {return __builtin_ctz(x); }

int max(int x, int y) {return x > y ? x : y;}

int **almostOKLCA**(int x, int y) {
    if (x == y) return x;
   
    int idx = msb(x ^ y); // x ^ y ne da toti biti care difera de la x si la y, iar msb(x ^ y) ne da primul numar care difera, de la stanga la dreapta

    int diff = 1 << idx;  //trebuie sa desetam toti biti de la msb(x ^ y) - 1 pana la 0
    return ans = (x & ~(diff - 1)) | diff; // si sa setam bitul  msb(x ^ y)
}
```
More about builtin gcc / g++ function can be found [here](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html)

Cum am marcat si in codul de mai sus, formula este aproape corecta. 
Cu ce /De ce  trebuie sa mai completati va las ca tema de casa.
Hint-ul este in ultima fraza din explicatia de mai sus. 

Solutia corecta
```cpp
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
```





