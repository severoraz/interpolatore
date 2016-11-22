# interpolatore
*n*-degree polynomial interpolator CLI utility.

FOSS coded in c++ and cross-platform. Relies on [Eigen][1] for linear algebra operations.

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
in non-linear functions, you may find this tool useful. Take a look at the image below:

![engine-chart](http://www.mpoweruk.com/images/power_torque.gif)

(image from www.mpoweruk.com)

Let's say we want to know what power the engine might deliver at 3000 min<sup>-1</sup>. The (red) power curve looks like it might be fitted nicely with a 2<sup>nd</sup> degree polynomial, so we take 3 points where engine angular speed and power are clearly readable, in this case (1000,20), (2000,50) and (4500,100). Now as the last parameter we use our known x value 3000:
```
$ interpolatore 1000 2000 4500 20 50 100 3000
y(x) = -15.7143 x^0 + 0.0385714 x^1 + -2.85714e-06 x^2
y = 74.2857
```
As results we get the corresponding y value and the polynomial abstracted from the known points.

[1]:http://eigen.tuxfamily.org/
