## Problema Grafului

Problema original se poate gasit pe [uva](https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2010)

Aceasta problema se rezolva prin programare dinamica.
Vom nota cu dp[i] = numarul de multimi ce se pot forma pentru un graf care are i noduri. Nodurile sunt 1, 2, 3, .., i.
Specific programari dinamice, vom considera toate raspunsurile de la 1 pana la i - 1 ca fiind deja calculate. 
Singurul lucru ce trebuie sa-l facem e sa gasim o relatie intre dp[i] si dp[i - 1], dp[i - 2], .. dp[1]


Cel mai simplu este sa analizam un exemplu. 
Consideram ca stim raspunsurile pentru i = 1, 2, 3, 4, 5, 6. 
Cum calculam raspunsul pentru i = 7 ?

Pentru i = 1 raspunsul este 1. Avem doar multimea {1}
       i = 2 raspunsul este 2. Avem multimiile {1} si {2}
       i = 3 raspunsul este 2. Avem multimiile {2} si {1, 3}. Multimea {1} nu mai este raspuns deoarce mai putem adauga un nod, nodul 3, care sa completeze multimea. Acest lucru incalca regula 2.
       i = 4 raspunsul este 3. Avem multimiile {1, 4}, {2, 4} si {1, 3}
       i = 5 raspunsul este 4. Avem multimiile {1, 4}, {2, 4}, {2, 5}, {1,3, 5}
       i = 6 raspunsul este 5. Avem multimiile {1, 4, 6}, {2, 4, 6}, {1, 3, 6}, {2, 5}, {1, 3, 5}

Grafurile de la i = 1, 6

![graf liniar cu 1 nod](https://raw.githubusercontent.com/SAlexandru/iTec/master/HighSchool/ProblemaGrafului/graph1.png?token=AC9vRcDiA25jqNc9CB29zFIMxPV-GR7Nks5Y8IJ_wA%3D%3D)

![graf liniar cu 2 noduri](https://raw.githubusercontent.com/SAlexandru/iTec/master/HighSchool/ProblemaGrafului/graph2.png?token=AC9vRce6b-GgMvebpC-03DhOO0AxYTCUks5Y8IKWwA%3D%3D)

![graf liniar cu 3 noduri](https://raw.githubusercontent.com/SAlexandru/iTec/master/HighSchool/ProblemaGrafului/graph3.png?token=AC9vRUDddSkrr4jlcXCu9NHHvf3iKgQqks5Y8ILIwA%3D%3D)

![graf liniar cu 4 noduri](https://raw.githubusercontent.com/SAlexandru/iTec/master/HighSchool/ProblemaGrafului/graph4.png?token=AC9vRXZjiS2oj2liv3Vv72C6XG1c2ijHks5Y8ILZwA%3D%3D


)
![graf liniar cu 5 noduri](https://raw.githubusercontent.com/SAlexandru/iTec/master/HighSchool/ProblemaGrafului/graph5.png?token=AC9vRfadDJCfHg15J4Cy4W0LA2DKThPlks5Y8ILswA%3D%3D)

![graf liniar cu 6 noduri](https://raw.githubusercontent.com/SAlexandru/iTec/master/HighSchool/ProblemaGrafului/graph6.png?token=AC9vRZD-dzc-LS1WJ12Ah9ecqbPU2ccuks5Y8IL4wA%3D%3D)
       
Pentru graful i = 7 
Avem poza: ![graf liniar cu 7 noduri](https://raw.githubusercontent.com/SAlexandru/iTec/master/HighSchool/ProblemaGrafului/graph7.png?token=AC9vRahnDiPQ07Gl-oxIJS5NSHzFD0_zks5Y8IMGwA%3D%3D)

Un lucru de observat este ca nu toate multimile de la i = 6 sunt raspunsuri pentru i = 7.
Un alt lucru de observat este faptul ca toate multimiile pentru un in contin fie elementul i fie elementul i - 1

De exemplu multimea {1, 3, 5} nu este valid pentru i = 7 intrucat putem adauga nodul 7 => regula 2 ar fi incalcata.
Am putea folosi  toate elementele de la i = 5, insa trebuie modificate pentru a deveni valide. Trebuie sa le mai adaugam
elmentul 7. Astfel am obtine multimiile {1, 4, 7}, {2, 4, 7}, {2, 5, 7}, {1, 3, 5, 7}. 

De ce putem adauga elementul 7 fara a avea problema ca un alt element sa fie vecin cu 7 ? Cel mai mare elment din toate
multimiile pentru i = 5 este elementul 5 care se gaseste la 2 noduri distance de 7.

De ce multimiile noi create sunt valide ?  Acest lucru va las tema de casa.

Insa nu am terminat ! Un lucru pe care il observa este faptul ca noi multimi nu au elmentul 6, acesta a fost "pierdut". 
Pentru a genera multimi care contin elementul 6 si sunt valide pentru i = 7 trebuie sa ne uitam la multimiile pentru
i = 4.   {1, 4}, {2, 4} si {1, 3} la toate putem adauga elementul 6 si devin valide. De ce ? Again, homework for you :).

Avand detaliile de mai sus recurenta devine: dp[i] = dp[i - 2] + dp[i - 3].
