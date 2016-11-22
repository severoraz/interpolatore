/*
 * Author: Sever Oraz
 * This is a linear interpolator that uses classic algebra
 */

#include <iostream>
#include <cstdlib>

int main(const int argc, const char* argv[]) {
    // $0 x0 x1 y0 y1 x -> y
    if (argc != 6) {
        std::cout << argv[0] << " x0 x1 y0 y1 x" << std::endl << 
            "Return: y" << std::endl;
        return 1;
    }
    else {
        float xn[2] = {strtof(argv[1],NULL), strtof(argv[2],NULL)};
        float yn[2] = {strtof(argv[3],NULL), strtof(argv[4],NULL)};
        float x = strtof(argv[5],NULL);

        // y-y0 = mx+b = (y1-y0)/(x1-x0)*(x-x0)
        // => y = y0 + (y1-y0)/(x1-x0)*(x-x0)

        float y = yn[0]+(yn[1]-yn[0])/(xn[1]-xn[0])*(x-xn[0]);

        std::cout << y << std::endl;

        return 0;
    }
}
