#include <iostream>
#include <cmath>

int main() {
    float x0, dx, xk;
    float a0, da, ak;

    std::cout << "Input x0, delta x, xk:" << std::endl;
    std::cin >> x0 >> dx >> xk;

    std::cout << "Input a0, delta a, ak:" << std::endl;
    std::cin >> a0 >> da >> ak;

    for (float x = x0; x <= xk; x += dx) {
        for (float a = a0; a <= ak; a += da) {
            std::cout << 2 * sqrt(a + 1) * cos(x) << std::endl;
        }
    }
}