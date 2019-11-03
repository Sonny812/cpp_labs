#include <iostream>
#include <iomanip>
#include <functional>
#include "lab.h"

#ifdef _WIN32
		#define CLEAR "cls"
	#else //In any other OS
		#define CLEAR "clear"
#endif


enum ProgramMenu { 
	MenuExit,
	MenuVectorLength,
	MenuScalarProduct,
	MenuMultiplyVectorByNumber,
	MenuMultiplyMatrixByNumber,
	MenuMultiplyMatrixByVector
};
ProgramMenu userSelectedMenuItem();

enum InputType {
	InputManual,
	InputAuto
};
InputType userSelectedInputType();

int main() {
	auto createVector = createVectorFromUserInput;
	auto createMatrix = createMatrixFromUserInput;
	InputType inputType = userSelectedInputType();

	if (inputType == InputAuto) {
		createVector = generateVector;
		createMatrix = generateMatrix;
	}

	while (true) {
		ProgramMenu menu = userSelectedMenuItem();

		switch (menu) {
			case MenuExit:
				exit(0);
				break;
			case MenuVectorLength: {
				double length;
				std::cout << "Enter vector length:" << std::endl;
				std::cin >> length;
				double *vector = createVector(length);
				printVector(vector, length);
				std::cout << "Vector length is " << vectorLength(vector, length);
				delete [] vector;
				break; 
			}
			case MenuScalarProduct: {
				double length;
				std::cout << "Enter vectors length:" << std::endl;
				std::cin >> length;
				std::cout << "First vector:" << std::endl;
				double *firstVector = createVector(length);
				std::cout << "Second vector:" << std::endl;
				double *secondVector = createVector(length);
				std::cout << "Vectors:" << std::endl;
				printVector(firstVector, length);
				printVector(secondVector, length);
				std::cout << "Scalar product is " << scalarProduct(firstVector, secondVector, length);
				delete [] firstVector;
				delete [] secondVector;
				break;
			}
			case MenuMultiplyVectorByNumber: {
				double length;
				std::cout << "Enter vector length:" << std::endl;
				std::cin >> length;
				double *vector = createVector(length);
				printVector(vector, length);
				double number;
				std::cout << "Enter number to multiplication: ";
				std::cin >> number;
				double *result = multiplyVectorByNumber(vector, length, number);
				printVector(result, length);
				delete [] vector;
				delete [] result;
				break;
			}
			case MenuMultiplyMatrixByNumber: {
				MatrixDimensions dimensions = MatrixDimensions::createFromUserInput();
				double **matrix = createMatrix(dimensions);
				printMatrix(matrix, dimensions);
				double number;
				std::cout << "Enter number to multiplication: ";
				std::cin >> number;
				double **resultMatrix = multiplyMatrixByNumber(matrix, dimensions, number);
				printMatrix(resultMatrix, dimensions);
				deleteMatrix(matrix, dimensions.getHeight());
				deleteMatrix(resultMatrix, dimensions.getHeight());
				break;
			}
			case MenuMultiplyMatrixByVector: {
				MatrixDimensions dimensions = MatrixDimensions::createFromUserInput();
				double **matrix = createMatrix(dimensions);
				printMatrix(matrix, dimensions);
				int length;
				double *vector = createVector(dimensions.getHeight());
				printVector(vector, dimensions.getHeight());
				double *result = multiplyMatrixByVector(matrix, vector, dimensions);
				printVector(result, dimensions.getHeight());
				deleteMatrix(matrix, dimensions.getHeight());
				delete [] vector;
				delete [] result;
			}
			default:
				break;
		}

		std::cout << std::endl;
		std::cin.ignore(255, '\n');
		std::cin.get();
		system(CLEAR);
	}
}

InputType userSelectedInputType() {
	int inputType;
	std::cout << "Select an input type (0 - manual, 1 - auto): ";
	std::cin >> inputType;

	return static_cast<InputType>(inputType);
}

ProgramMenu userSelectedMenuItem() {
	int menuItem;
	std::cout <<  
R"(Select a menu item: 
1. Vector length.
2. Scalar product.
3. Multiply vector by number.
4. Multiply matrix by number.
5. Multiply matrix by vector.

0. Exit.
)";
	std::cout << "Your choice: ";
	std::cin >> menuItem;

	return static_cast<ProgramMenu>(menuItem);
}
