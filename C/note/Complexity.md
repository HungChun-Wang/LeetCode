### Sort

|           |     Time_Avg      |  Time_Best  |                             Time_Worst                              |                                      Space                                       | Stability | Note                 |
| :-------- | :---------------: | :---------: | :-----------------------------------------------------------------: | :------------------------------------------------------------------------------: | :-------: | -------------------- |
| bubble    |     $O(n^2)$      |   $Ω(n)$    |                              $O(n^2)$                               |                                      $O(1)$                                      |    $Y$    |                      |
| selection |     $O(n^2)$      |   $Ω(n)$    |                              $O(n^2)$                               |                                      $O(1)$                                      |    $N$    |                      |
| insertion |     $O(n^2)$      |   $Ω(n)$    |                              $O(n^2)$                               |                                      $O(1)$                                      |    $Y$    |                      |
| shell     | $O(n^{\frac 54})$ |   $Ω(n)$    | $O(n^2)] step \frac {n}{2^i}$<br>$O(n^{\frac 32}) step (4^i-2^i-1)$ |                                      $O(1)$                                      |    $N$    |                      |
| quick     |    $O(n*logn)$    | $Ω(n*logn)$ |                              $O(n^2)$                               | $O(n)$ $iterration$<br>$O(n)$ $tail$ $recursive$<br>$O(logn)$ $rand$ $recursive$ |    $N$    |                      |
| merge     |    $O(n*logn)$    | $Ω(n*logn)$ |                             $O(n*logn)$                             |                                      $O(n)$                                      |    $Y$    |                      |
| counting  |     $O(n+k)$      |  $Ω(n+k)$   |                              $O(n+k)$                               |                      $O(k)$ $unstable$<br>$O(n+k)$ $stable$                      |    $Y$    | $k: value$ $number$  |
| bucket    |     $O(n+k)$      |  $Ω(n+k)$   |                              $O(n^2)$                               |                                     $O(n+k)$                                     |    $Y$    | $k: bucket$ $number$ |
| radix     |      $O(dn)$      |   $O(dn)$   |                               $O(dn)$                               |                                     $O(d+n)$                                     |     Y     | $d: digits$ $number$ |
|           |                   |             |                                                                     |                                                                                  |           |                      |

Stablility 穩定性: 
相同值的位置, 在排序前後, 順序是否一樣