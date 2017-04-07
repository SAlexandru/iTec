## Sali de Meeting


Aceasta problema poate fi reformulata: 
  > Se da un set de intervale [a, b], a < b. 
  > Se cere sa se determine numarul maxim de intervale deschise la un moment dat. 
  
Un mod de a rezolva aceasta problema este de a "sparge" intervalul in doua componente a si b. In acelasi timp trebuie sa 
marcam cumva "a" ca find partea de start a intervalului si "b" partea de end a intervalului.  Astfel din N intervale am creat
2 * N numere. Acestea le putem sorta in ordine crescatoare. Daca avem doua numere identice, *numarul care reprezinta sfarsitul
unui intervalului trebuie sa apara inainte de numarul, cu aceasi valoare, care reprezinta inceputul intervalului*.
Dupa ce le-am sortat, putem sa ne plimba cu un contor care il incrementam cand dam peste un numar care reprezinta un interval
deschis, si decrementam cand dam peste un numar care reprezinta un sfarsit de interval. Valoarea cea mai mare care este
atina de contor este raspunsul de la problema. Valoarea cea mai mare reprezinta numarul maxim de interval care sunt deschise
la un anumit punct in timp.
