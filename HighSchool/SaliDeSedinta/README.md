## Sali de Sedinta


Aceasta problema poate fi reformulata: 
  > Se da un set de intervale [a, b], a < b. 
  >
  > Se cere sa se determine numarul maxim de intervale deschise la un moment dat. 
  
Pentru a rezolva aceasta problema vom "insira" toate numerele pe axa numerelor reale si vom marca cu [ un numar de pe axa ce reprezinta inceputul unui interval si cu [ sfarsitul de interval.

De exemplu pentru datele de test:
```
9
1 5
2 5
3 5
4 5
5 6
5 7
5 8
5 9
5 10
```
Imaginea asociata acestor date este:
![Numbers on an axe](https://raw.githubusercontent.com/SAlexandru/iTec/master/HighSchool/SaliDeSedinta/intervals.png)

Acum raspunsul este destul de usor de observat, numarul maxim de intervale deschise la un moment dat este 5. 
Un lucru foarte important de observat (cel putin pentru implementare) este: daca la acelasi numar se deschid si inchid intervale trebuie **numarate prima data cate intervale se inchid, apoi sa se numere cate se deschid**
