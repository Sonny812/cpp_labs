#include <iostream>
#include <cmath>

int main() {
    const int size = 10;
    float *numbers = new float[size];
    float *results = new float[size];

    
    std::cout << "Input 10 numbers: " << std::endl;
    for (int i=0; i<10; i++) {
        float number;
        std::cin >> number;
        numbers[i] = number;

        if (number <= 0) {
            results[i] = number * number;
        } else if (number <= 2) {
            results[i] = number - 58;
        } else if (number <= 5) {
            results[i] = cos(number);
        } else {
            results[i] = 0;
        }
    }

    auto printArr = [](float *arr, int length) {
        for (int i = 0; i < length; i++) {
            std::cout << *(arr + i) << " ";
        }  
    };

    std::cout << "Points: ";
    printArr(numbers, size);
    std::cout << std::endl;

    std::cout << "Results: ";
    printArr(results, size);
    std::cout << std::endl;
}