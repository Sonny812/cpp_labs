#include <iostream>
#include <cmath>

double facto(double x)
{
    return x <= 1 ? 1 : x * facto(x - 1);
}

int main()
{
    const auto originalFunction = [] (double x) {
        return sin(x) / x;
    };

    const double x = 0.52;
    const double precision = 0.5 * pow(10, -3);

    double F = 1;
    double F0 = 0;
    double factorial = 1;
    double i;
    
    for (i = 1; fabs(F - F0) > precision; i++)
    {
        F0 = F;
        F += pow(-1, i) * (pow(x, 2 * i) / facto(2 * i + 1));
    }

    double originalResult = originalFunction(x);
    std::cout << F << std::endl;
    std::cout << originalResult << std::endl;
    if (fabs(originalResult - F) < precision) {
        std::cout << "The results are equal" << std::endl;
    }
    std::cout << "Count of iterations: " << i << std::endl;
}