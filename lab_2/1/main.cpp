#include <iostream>
#include <cmath>

int main() {
    float a, b, c;

    std::cout << "Input equation coeffiecients (a, b, c):" << std::endl;
    std::cin >> a >> b >> c;
    
    if (a == 0) {
        std::cout << "The equation is not biquadtratic" << std::endl;
        exit(0);
    }

    float d = b * b - 4 * a * c;

    if (d < 0) {
        std::cout << "The equation has no roots" << std::endl;
        exit(0);
    }

    float t1 = (-b + sqrt(d)) / (2 * a);
    float t2 = (-b - sqrt(d)) / (2 * a);

    if (t1 < 0 || t2 < 0 || t1 == t2) {

        if (t1 < 0 && t2 < 0) {
            std::cout << "The equation has no roots" << std::endl;
            exit(0);
        }
        float xSqr = t1 > t2 ? t1 : t2;
        std::cout << "Roots:" << std::endl << "x1  = " << sqrt(xSqr) << std::endl << "x2 = " << -sqrt(xSqr) << std::endl;
        exit(0);
    }

    std::cout << "Roots:" << std::endl;
    std::cout << "x1 = " << sqrt(t1) << std::endl << "x2 = " << -sqrt(t1) << std::endl;
    std::cout << "x3 = " << sqrt(t2) << std::endl << "x4 = " << -sqrt(t2) << std::endl;

}