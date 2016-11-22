/*
 * Author: Sever Oraz
 * This is a n-degree-polynomial interpolator that uses Matrix arithmetic
 * instead of classic algebra.
 */

#include <iostream>
// #include <cmath>
#include <vector>
#include <cstdlib>
#include <Eigen/Core>
#include <Eigen/LU>

int main(const int argc, const char* argv[]) {
    // Exit when wrong parameters
    if (((argc-1)%2==0) 
            || (argc <= 4)) {
        std::cout << argv[0] << " x1 x2 ... xn y1 y2 ... yn x" << std::endl
            << "Return: y" << std::endl;
        return 1;
    }
    // For now, just ignore if parameters are not numbers
    
    int p = (argc-2)/2;
    int n = p-1; // polynomium degree

    // Known values
    Eigen::MatrixXd X(p,p);
    // X << 1, xn[0], 1, xn[1];
    // x1^0 x1^1 ... x1^n
    // xn^0 xn^1 ... xn^n

    Eigen::VectorXd Y(p);
    // y1, y2, ..., yn

    Eigen::VectorXd x(n+1);
    // xm^0 xm^1 ... xm^n

    // n = p - 1
    double h = 0.0;
    double k = strtod(argv[1+p*2],NULL);

    // Populate known structures
    for (int i=0; i<p; i++) {
        h = strtod(argv[i+1],NULL);
        for (int j=0; j<=n; j++) {
            X(i,j)=pow(h,j);
        }
        Y[i]=strtod(argv[1+p+i],NULL);
        x[i]=pow(k,i);
        i*=1;
    }
    
    // Calculate auxiliary variables
    Eigen::MatrixXd Xt = X.transpose();
    Eigen::MatrixXd Z = Xt*X;

    // Unknowns
    Eigen::VectorXd C(n+1);
    double y = 0.0;

    // Solution
    C = Z.inverse()*Xt*Y;
    y = C.dot(x);

    // Reveal function
    std::cout << "y(x) = ";
    for (int i=0; i<=n; i++) {
        // c_n x^n
        std::cout << C[i] << " x^" << i;
        if (i!=n) std::cout << " + ";
    }
    std::cout << std::endl;

    // Reveal
    // std::cout << "X:\n" << X << std::endl;
    // std::cout << "Xt:\n" << Xt << std::endl;
    // std::cout << "Z:\n" << Z << std::endl;
    // std::cout << "C:\n" << C << std::endl;
    std::cout << "y(" << x[1] << ") = " << y << std::endl;

    return 0;
}
