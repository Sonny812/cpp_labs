#include <iostream>
#include <fstream>
#include <cmath>

double f(double x)
{
    return x * cos(x);
}

int main()
{
    const std::string filename = "results.txt";
    double x1, dx, xn;

    std::cout << "Enter x1, dx, xn:" << std::endl;
    std::cin >> x1 >> dx >> xn;

    std::ofstream os(filename);

    for (double x = x1; x <= xn; x += dx)
    {
        os << f(x) << std::endl;
    }

    os.close();
}