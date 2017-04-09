## Cautare Bitonic

Aceasta problema este destul de straight forward.
Va trebui sa modificam cautarea binara a.i sa putem cauta in sir.
Am putea folosi 3 cautari binare, 1 pentru a gasi pivotul si inca doua pentru cele doua parti ale sirului.
Desigur, putem elimina cea pentru gasirea pivotului putand afla unde se afla pivotul in timpul citiri.
In acelasi timp am putea sa modificam cautarea binara fara sa tinem cont de pivot.

Algoritmul in pseudocod: 

```
v -- vectorul in care cautam

void bitonic_search(int value, int left, int right) { // vom cauta de la [left, right)
    if (left >= right) return ; // intervalul este gol
    else if (left + 1 == right) { ... } //avem doar un element: v[left]
    else if (left + 2 == right) { ... } //avem doar doua elemente: v[left] si v[left + 1]
    
    int middle = left + (right - left) / 2; // daca folosim (right + left) / 2 putem face overflow. (Ma rog, nu pe datele de test, dar in practice) 
    
    if (v[x] == middle) {
       //am gasit elementul cautat
    }
    
    //avem cel putin trei elemente
    if (v[middle - 1] < v[middle] && v[middle] < v[middle + 1]) {
       //stim sigur ca intervalul [left, middle] este strict crescator
       if (x < v[middle]) {
          ascending_binary_search(value, left, middle);
       }
       bitonic_search(value, middle + 1, right); // numarul poate sa mai apara si in intervalul (middle, right)
    }
    else if (v[middle - 1] > v[middle] && v[middle] > v[middle + 1]) {
        //stim sigur ca intervalul [middle, right) este strict descrescator
        if (x < v[middle]) {
           descending_binary_search(value, middle + 1, right);
        }
        bitonic_search(value, left, middle);
    }
    else {
         //am gasit pivotul
        ascending_binary_search(value, left, middle);
        descending_binary_search(value, middle + 1, right);
    }
}
```
