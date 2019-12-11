#include <iostream>
#include "complex.hpp"

int main()
{
    Complex firstNumber, secondNumber;

    std::cout << "Enter real and imaginary part of fisrt complex number:" << std::endl;
    std::cin >> firstNumber;
    std::cout << "Enter real and imaginary part of second complex number:" << std::endl;
    std::cin >> secondNumber;

    std::cout << "Sum: " << firstNumber + secondNumber << std::endl;
    std::cout << "Difference: " << firstNumber - secondNumber << std::endl;
    std::cout << "Product: " << firstNumber * secondNumber << std::endl;
    std::cout << "Quotient: " << firstNumber / secondNumber << std::endl;

    Complex thirdNumber = Complex(firstNumber);

    if (firstNumber == secondNumber) // the condition should be false and the message shouldn't be displayed
    {
        std::cout << "First and second numbers are equals" << std::endl;
    }

    if (firstNumber == thirdNumber)
    {
        std::cout << "First and third numbers are equal" << std::endl;
    }
}