## Triunghiuri

Problema aceasta se gaseste si pe [uva](https://www.google.ro/url?sa=t&rct=j&q=&esrc=s&source=web&cd=1&cad=rja&uact=8&ved=0ahUKEwionsba1JfTAhXCbxQKHbw-ARgQFggaMAA&url=https%3A%2F%2Fuva.onlinejudge.org%2Findex.php%3Foption%3Donlinejudge%26page%3Dshow_problem%26problem%3D2549&usg=AFQjCNHlqtQ1PfatA0CP2qwGIxSskDISVg&sig2=zPXeUhGxXW5V19WKQ8vQ1A)

This can be solved using dynamic programing.
```
Let dp[i] = #of integers from 1 .. i that satisfy the inequalities.
let m = i >> 1
dp[i] = dp[i - 1] + m * (m - 1)
if (i is even) dp[i] -= m - 1
```

How did we deduce the formula?

Considera n = 7: 1 2 3 4 5 6 7 

dp[3] = 0, dp[4] = 1, dp[5] = 3, dp[6] = 7

Obviously all the solutions from dp[6] are still valid and we don’t have to consider older ones because they are already counted for in dp[6].  
Now we have to count how many pairs of a, b, c work for when c = 7, the new element, in our case.  One observation is that we need to count how many pairs of number a, b satisfy a + b > c . The rest of the conditions are satisfied because c > a and c > b for any a, b.
Let’s count how many pair satisfy this constraint. 




Well if a = 1 we have no b s.t 1 + b > c = 7
        a = 2 we have one element: 6 s.t 2 + b > c = 7
        a = 3 we have two elements: 5 and 6 s.t 3 + b > c = 7
        a = 4 we have two elements: 5 and 6 s.t 4 + b > c = 7
        a = 5 we have one element: 6 s.t 6 + b > c = 7
        a = 6 we have no element 

In total we have 0 + 1 + 2 + 2 + 1 + 0 = 6
dp[7] = dp[6] + 6 = 7 + 6 = 13

One thing that is interesting is that after 3 (7 / 2) we see that 4, 5 and 6 mimic what was before for 3 (7 - 4), 2 (7 - 5), 1 (7 - 6). I will let you figure out why this holds for every n.  
The number of elements is basically 2 * (0 + 1 + 2 + … + n / 2) = 2 * (0 + 1 + 2 + … + m / 2) = m * (m - 1)
Now for even numbers we have counted the number of elements for n / 2 twice. This can be solved by subtracting m - 1.  
  


We need unsigned long long int for C++ 
