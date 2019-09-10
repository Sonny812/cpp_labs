#include <iostream>
#include <iomanip>

template <typename T>
T **multiply(T **matrix, int width, int height, float number) {
	T **multipliedMatrix = new T*[width];
	for (int i = 0; i < width; i++) {
		multipliedMatrix[i] = new T[height];
		for (int j = 0; j < height; j++) {
			multipliedMatrix[i][j] = number * matrix[i][j];
		}
	}

	return multipliedMatrix;
}

template <typename T>
void printMatrix(T **matrix, int width, int height) {
	for(int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::cout << std::setw(4) << matrix[i][j];
		}
		std::cout << std::endl;
	}
}

int main() {
	int rowCount, colCount;
	std::cout << "Enter matrix dimensions:" << std::endl;
	std::cin >> rowCount >> colCount;

	int **matrix = new int*[rowCount];

	for (int i = 0; i < rowCount; i++) {
		matrix[i] = new int[colCount];
	}

	for (int i = 0; i < rowCount; i++) {
		for (int j = 0; j < colCount; j++) {
			matrix[i][j] = rand() % 100;
		}
	}

	printMatrix(matrix, rowCount, colCount);

	int number;
	std::cout << "Enter number to multiply: ";
	std::cin >> number;
	
	printMatrix(multiply(matrix, rowCount, colCount, number), rowCount, colCount);
}
