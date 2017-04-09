## Ecuatia Dreptei

Aceasta problema este cea mai simpla din set-ul pentru universitate.
Presupune evaluarea / simplificarea a doua expresii matematice. Un algortim, poate prea complicat pentru aceasta problema
poate fi gasit [aici](http://www.infoarena.ro/problema/evaluare)

Poate ce mai "grea" parte este calcularea distantei de la punctul (0, 0) la dreapta data ca si ecuatie.
Daca ecuatia dreptei d este de forma a * x + b * y + c = 0, poate fi demonstrat ca distanta de la dreapta d la punctul
(0, 0) este: [```|c| / sqrt(a * a + b * b)```](https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line)

Un mod de a deduce formula este sa observam ca distance de la dreapta d la punctul (0, 0) este egala cu inaltimea triunghiului
format de punctul (0, 0) si doua puncte P0 si P1 care se afla pe dreapta. In aceste conditii formula ar fi: ```h = (2 * A) / b)```
unde A este aria triunghiului, iar b lungimea dreptei intre punctele P0 si P1. ```b = sqrt( (x1 - x0)^2 + (y1 - y0) ^ 2)```

Aria triunghiului se poate calcula folosind determinanti:
```
A = 1/2 * | x0 y0 1 |
          | x1 y1 1 |
          | 0  0  1 | 
          
A = 1/2 * (x0 * y1 - x1 * y0)          
```
