#include <iostream>
#include <string>
#include <iomanip>

int main() {
    int direction;
    std::cout << "Choose direction (0 - down, 1 - right): ";
    std::cin >> direction;
    bool downDirection = direction == 0;

    int countToShift;
    std::cout << "Enter count of elements to shift: ";
    std::cin >> countToShift;

    int height, width;

    std::cout << "Enter matrix dimensions:" << std::endl;
    std::cin >> height >> width;

    countToShift = downDirection ? countToShift % height : countToShift % width;

    int **sourceMatrix = new int*[height];
    int **shiftedMatrix = new int*[height];
    for (int i = 0; i < height; i++) {
        sourceMatrix[i] = new int[width];
        shiftedMatrix[i] = new int[width];
        for (int j = 0; j < width; j++) {
            std::cout << "Element [" << i << "]" << "[" << j << "]:";
            std::cin >> sourceMatrix[i][j];
            // debugging
            // sourceMatrix[i][j] = rand() % 100;
        }
    }

    auto printMatrix = [] (int **matrix, int width, int height) {
        for (int i=0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                std::cout << std::setw(5) << matrix[i][j];
            }
            std::cout << std::endl;
        }
    }; 

    printMatrix(sourceMatrix, width, height);
    std::cout << std::endl;

    if (downDirection) {
        for (int i = 0; i < countToShift; i++) {
            for (int j = 0; j < width; j++) {
                shiftedMatrix[i][j] = sourceMatrix[height - countToShift + i][j];
            }
        }
        for (int i = countToShift; i < height; i++) {
            for (int j = 0; j < width; j++) {
                shiftedMatrix[i][j] = sourceMatrix[i-countToShift][j];
            }
        }
    } else {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < countToShift; j++) {
                shiftedMatrix[i][j] = sourceMatrix[i][width - countToShift + j];
            }
        }
        for (int i = 0; i < height; i++) {
            for (int j = countToShift; j < width; j++) {
                shiftedMatrix[i][j] = sourceMatrix[i][j-countToShift];
            }
        }
    }

    printMatrix(shiftedMatrix, width, height);
}