#include <iostream>
#include <cmath>

int main() {
    float x0, deltaX;
    int n;
    std::cout << "Enter x0, delta x, and n:" << std::endl;
    std::cin >> x0 >> deltaX >> n;
    float x = x0;
    for (int i=0; i < n; i++, x += deltaX) {
        std::cout << "f(" << x << ") = " << 12.4 / (sqrt(x) - x * x) << std::endl; 
    } 
}