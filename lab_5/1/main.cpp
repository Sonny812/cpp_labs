#include <iostream>

int main() {
    int n, x;
    std::cout << "Input n, x" << std::endl;
    std::cin >> n >> x;
    float result = 0;


    for (int i=1; i <= n; i++) {
        float subresult = 1;
        for (int j=0; j < 2 * i; j++) {
            subresult *= x;
        }
         result += subresult;
    }

    std::cout << "Result: " << result << std::endl;
}