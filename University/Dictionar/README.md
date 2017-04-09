## Dictionar


Daca am considera cuvintele noduri, problema nu cere nimice altceva decat distanta miniam intre doua noduri. 
Ne avand costuri pe muchi, distanta minima se poate calcula folosind [BFS (parcurgerea in latime)](http://www.infoarena.ro/problema/bfs)

Singura problema ar fi construirea acestui graf. 
Daca cuvintele ar fi noduri, avem o muchie intre doua noduri A si B daca si numai daca cuvantul A poate fi transformat in 
cuvantul B. Desigur graful este neorientat intrucat daca putem transforma A in B putem sa transformam si pe B in A.

De exemplu:
```
4 6
ana
bna
bma
ama
ana bna
ana ama
ana bma
bna bma
bna ama
bma ama

Avem nodurile ana, bna, bma si ama
Avem muchii intre:
   ana si bna (b poate fi inlocuit cu a si invers)
   ana si ama (n poate fi inlocuit cu m si invers)
   bna si bma (n poate fi inlocuit cu m si invers)
   bma si ama (b poate fi inlocuit cu a si invers)
 ```
 
 Poza pentru graful de mai sus ar fi:
 ![graf cu 4 noduri si 4 muchi, un graf stea](https://raw.githubusercontent.com/SAlexandru/iTec/master/University/Dictionar/tests/photosOfTheGraphs/input1.png)

In folderul [tests/photosOfTheGraphs](https://github.com/SAlexandru/iTec/tree/master/University/Dictionar/tests/photosOfTheGraphs) 
gasiti pozele grafurilor care au fost date ca si teste :) Aceste poze au fost generate folosind [graphviz](http://www.graphviz.org/)
in care se poate da un fisier care descrie nodurile si muchiile din graf. Fisierul trebuie scris in limbajul [dot](http://www.graphviz.org/content/dot-language). 
Pentru testele noastre fisierele .dot se gasesc in in folderul test/dotFiles.
Pentru a genera o imagine dintr-un fisier dot puteti folosi comanda dot -Tpng <nume fisier>.dot -o <num imagine>.png
