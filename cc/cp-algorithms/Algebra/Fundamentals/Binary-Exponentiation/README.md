# [Binary Exponentiation](https://cp-algorithms.com/algebra/binary-exp.html)

- It is a trick that allows to calculate a<sup>n</sup> in O(log(n)) instead of O(n).

- Can use it with any operation that has the property of Associativity
(X Y) Z = X (Y Z)

## Algorithm

a<sup>b+c</sup> = a<sup>b</sup>. a<sup>c</sup>
<br>
eg.
3<sup>13</sup> = 3<sup>1101<sub>2</sub></sup> = 3<sup>8</sup> . 3<sup>4</sup> . 3<sup>1</sup>


## Code
```c++
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

```
