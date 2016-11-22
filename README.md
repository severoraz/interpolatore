# interpolatore
*n*-degree polynomial interpolator CLI utility.

# Usage syntax
Provide *n* points to define an *(n-1)*<sup>th</sup> degree polynomial, and specify the *x* value 
for which you want to know *y(x)*

`$ interpolatore x1 x2 ... xn y1 y2 ... yn x`

For example:

```
$ interpolatore 1 2 3 4 5
y(x) = 2 x^0 + 1 x^1
y(5) = 7
```
# Example use case

If you frequently have to read charts and sometimes feel uncomfortable doing linear interpolations 
in non-linear functions, you may find this tool useful.
