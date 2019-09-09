#include <iostream>
#include <cmath>

int main() {
    float a, b, x;

     std::cout << "Input a, b, x:" << std::endl;

     std::cin >> a >> b >> x;

     float y = (pow(b, 2) - pow(x, 3)) / cos(2 * a);

     std::cout << "Y = " << y << std::endl;
}