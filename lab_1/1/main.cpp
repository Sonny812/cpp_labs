#include <iostream>
#include <cmath>

int main() {
    float a, b, c;

    std::cout << "Input a, b, c: " << std::endl;
    std::cin >> a >> b >> c;

    float d = sqrt(a * a + b * b + c * c);

    std::cout << "D  = " << d << std::endl;
}