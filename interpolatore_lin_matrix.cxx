/*
 * Author: Sever Oraz
 * This is a linear interpolator that uses Matrix arithmetic instead 
 * of classic algebra.
 */

#include <iostream>
#include <cstdlib>
#include <Eigen/Core>
#include <Eigen/LU>

int main(const int argc, const char* argv[]) {
    // $0 x0 x1 y0 y1 x -> y
    if (argc != 6) {
        std::cout << argv[0] << " x0 x1 y0 y1 x" << std::endl << 
            "Return: y" << std::endl;
        return 1;
    }
    else {
        // Convert parameters to floats
        float xn[2] = {strtof(argv[1],NULL), strtof(argv[2],NULL)};
        float yn[2] = {strtof(argv[3],NULL), strtof(argv[4],NULL)};

        // Known values
        Eigen::Matrix2f X;
        X << 1, xn[0], 1, xn[1];
        Eigen::Matrix2f Xt = X.transpose();
        Eigen::Matrix2f Z = Xt*X;

        Eigen::Vector2f Y(yn[0],yn[1]);

        Eigen::Vector2f x(1,strtof(argv[5],NULL));
        
        // Unknowns
        Eigen::Vector2f C;
        float y = 0.0;

        // Solution
        C = Z.inverse()*Xt*Y;
        y = C.dot(x);

        // Reveal
        std::cout << y << std::endl;

        return 0;
    }
}
