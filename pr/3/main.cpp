#include <iostream>
#include <cmath>

int main()
{
    const double x = -2.5;
    const double precision = 0.1 * pow(10, -3);

    double P = 2;
    double P0 = 0;
    double iFactorial = 1;
    double i;
    for (i = 1; fabs(P - P0) > precision; i++, iFactorial *= i) {
        P0 = P;
        P += (pow(-1, i) * (x + 1)) / iFactorial;
    }

    std::cout << P << std::endl;
    std::cout << "Count of iterations: " << i << std::endl;
}