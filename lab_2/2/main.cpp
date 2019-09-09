#include <iostream>
#include <cmath>

int main() {
    float x, y;

    std::cout << "Input x: ";
    std::cin >> x;

    if (0.2 < x && x <= 0.3) {
        y = sqrt(abs(log(0.2 * 0.2 - x * x)));
        std::cout << "1" << std::endl;
    } else if (0.3 < x && x <= 0.9) {
        y = 1;
        std::cout << "2" << std::endl;
    } else if (0.9 <= x && x <= 1) {
        y = 0.5 * pow(cos(x / 2), 2);
        std::cout << "3" << std::endl;
    } else if (x > 1) {
        y = tan(x);
        std::cout << "4" << std::endl;
    }

    std::cout << "Y = " << y << std::endl;
}