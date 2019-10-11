#include <iostream>

int main() {
    int number;
    int count = 0;
    std::cout << "Input a positive number: ";
    std::cin >> number;

    for (int i = 1; i <= number; i++) {
        int m = i;
        int p = 0;
        while (m > 0) {
            int s = m % 10;
            p = p * 10 + s;
            m /= 10;
        }
        if (p == i) {
           count += 1;
        }
    }

    std::cout << "There is " << count << " palindrom(s) in 1.." << number << " range" << std::endl;
}