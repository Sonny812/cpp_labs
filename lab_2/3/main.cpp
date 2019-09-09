#include <iostream>

int main() {
    int result;
    std::cout << "Input test result: ";
    std::cin >> result;

    switch (result)
    {
        case 90 ... 100:
            std::cout << "Excellent" << std::endl;
            break;
        case 70 ... 89:
            std::cout << "Good" << std::endl;
            break;
        case 50 ... 69:
            std::cout << "Satisfactory" << std::endl;
            break;
        default:
            std::cout << "Failure" << std::endl;
            break;
    }
}