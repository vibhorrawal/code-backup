# [Ternary Search](https://cp-algorithms.com/num_methods/ternary_search.html)

- A function f(x) which is unimodal on interval [l,r], unimodal is one of following two behaviors:

i. The function strictly increases first, reaches a `maximum`, and then strictly decreases.
<br/>
ii. The function strictly decreases first, reaches a `minimum`, and the strictly increases.

We can find max/min of f(x) in interval [l,r], using ternary search in O(log(n))


## Algorithm
We take two points m1, m2 s.t. `l < m1 < m2 < r` the following cases may arise(case for maximum):
- `f(m1) < f(m2)`
\
maximum is in [m1, r]

- `f(m1) > f(m2)`
\
maximum is in [l, m2]

- `f(m1) == f(m2)`
\
  search space is reduced to [m1, m2]

### Choice of m
`m1 = l + (r-l)/3`
\
`m2 = r - (r-l)/3`

## Code

```c++
double ternary_search(double l, double r) {
    double eps = 1e-9;              
    REP(i,100) { // better than r-l > eps for most cases
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);     
        double f2 = f(m2);      
        if (f1 < f2) // for finding minimum, use > instead
            l = m1;
        else
            r = m2;
    }
    return f(l);                   
}
```
----
```c++
int ternary_search(int l, int r) {
  REP(i,100) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    if (f(m1) < f(m2))
      l = m1;
    else
      r = m2;
  }
  return f(l);                    
}

```
