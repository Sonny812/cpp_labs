#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <tuple>
#include <cmath>
#include "lab.h"

double vectorLength(double *vector, int length) {
	double sumOfVectorRoots = 0;
	for (int i = 0; i < length; i++) {
		sumOfVectorRoots += vector[i] * vector[i];
	}

	return sqrt(sumOfVectorRoots);
}

double scalarProduct(double *firstVector, double *secondVector, int length) {
	double scalarProduct = 0;
	for (int i = 0; i < length; i++) {
		scalarProduct += firstVector[i] * secondVector[i];
	}

	return scalarProduct;
}

double* multiplyVectorByNumber(double *vector, int length, double number) {
	double *resultVector = new double[length];
	for (int i = 0; i < length; i++) {
		resultVector[i] = vector[i] * number;
	}

	return resultVector;
}

double **multiplyMatrixByNumber(double **matrix, MatrixDimensions dimensions, double number) {
	double **multipliedMatrix = new double*[dimensions.getHeight()];
	for (int i = 0; i < dimensions.getHeight(); i++) {
		multipliedMatrix[i] = new double[dimensions.getWidth()];
		for (int j = 0; j < dimensions.getWidth(); j++) {
			multipliedMatrix[i][j] = number * matrix[i][j];
		}
	}

	return multipliedMatrix;
}

double *multiplyMatrixByVector(double **matrix,  double* vector, MatrixDimensions dimensions) {
	double *resultVector = new double[dimensions.getHeight()];
	for (int i = 0; i < dimensions.getHeight(); i++) {
		resultVector[i] = 0;
		for (int j = 0; j < dimensions.getWidth(); j++) {
			resultVector[i] += matrix[i][j] * vector[j];
		}
	} 

	return resultVector;
}

// Returns tuple where first element is the pointer to the matrix and second element is the matrix dimensions
std::tuple<double**,MatrixDimensions> multiplyMatrixByMatrix(double **firstMatrix, MatrixDimensions firstDimensions, double **secondMatrix, MatrixDimensions secondDimensions) {
	if (firstDimensions.getWidth() != secondDimensions.getHeight()) {
		throw std::logic_error("Unable to multiple the matrices. First matrix width should be equal to second matrix height");
	}

	MatrixDimensions resultMatrixDimensions = MatrixDimensions(firstDimensions.getHeight(), secondDimensions.getWidth());
	double **resultMatrix = new double*[resultMatrixDimensions.getHeight()];
	for (int i = 0; i < resultMatrixDimensions.getHeight(); i++) {
		resultMatrix[i] = new double[resultMatrixDimensions.getWidth()];
	}

	for (int i = 0; i < firstDimensions.getHeight(); i++) {
		for (int j = 0; j <  secondDimensions.getWidth(); j++) {
			for (int k = 0; k < firstDimensions.getWidth(); k++) {
				resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
		}
	}

	return std::make_tuple(resultMatrix, resultMatrixDimensions);
}

void minor(double **matrix, double **minorMatrix, int size, int row, int column) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i < row) {
				if (j < column) {
					minorMatrix[i][j] = matrix[i][j];
				} else if (j > column){
					minorMatrix[i][j-1] = matrix[i][j];
				}
			} else if (i > row) {
				if (j < column) {
					minorMatrix[i-1][j] = matrix[i][j];
				} else if (j > column) {
					minorMatrix[i-1][j-1] = matrix[i][j];
				}
			}
		}
	}
}

double findMatrixDeterminant(double **matrix, MatrixDimensions dimensions) {
	if (dimensions.getHeight() == 1) {
		return matrix[0][0];
	} 

	double result = 0;
	int sign = -1;
	int actualSize = dimensions.getHeight() - 1;

	for (int i = 0; i < dimensions.getHeight(); i++) {
		double **minorMatrix = new double*[actualSize];
		for ( int j = 0; j < actualSize; j++) {
			minorMatrix[j] = new double[actualSize];
		}

		minor(matrix, minorMatrix, dimensions.getHeight(), 0, i);

		sign *= -1;

		result += sign * matrix[0][i] * findMatrixDeterminant(minorMatrix, MatrixDimensions(actualSize, actualSize));

		deleteMatrix(minorMatrix, actualSize);
	}

	return result;
} 

double** addMatrixToMatrix(double **firstMatrix, double **secondMatrix, MatrixDimensions dimensions) {
	double **resultMatrix = new double*[dimensions.getHeight()];
	for (int i = 0; i < dimensions.getHeight(); i++) {
		resultMatrix[i] = new double[dimensions.getWidth()];
		for (int j = 0; j < dimensions.getWidth(); j++) {
			resultMatrix[i][j] = firstMatrix[i][j] + secondMatrix[i][j];
		}
	}

	return resultMatrix;
}


double* generateVector(int length) {
	double *vector = new double[length];
	for (int i = 0; i < length; i++) {
		vector[i] = rand() % 100;
	}

	return vector;
}

double* createVectorFromUserInput(int length) {
	double *vector = new double[length];

	for (int i = 0; i < length; i++) {
		std::cout << "Element [" << i << "]: ";
		std::cin >> vector[i];
	}

	return vector;
}

double** generateMatrix(MatrixDimensions dimensions) {
	double **matrix = new double*[dimensions.getHeight()];

	for (int i = 0; i < dimensions.getHeight(); i++) {
		matrix[i] = new double[dimensions.getWidth()];
		for (int j = 0; j < dimensions.getWidth(); j++) {
			matrix[i][j] = rand() % 100;
		}
	}

	return matrix;
}

double** createMatrixFromUserInput(MatrixDimensions dimensions) {
	double **matrix = new double*[dimensions.getHeight()];

	for (int i = 0; i < dimensions.getHeight(); i++) {
		matrix[i] = new double[dimensions.getWidth()];
		for (int j = 0; j < dimensions.getWidth(); j++) {
			std::cout << "Element [" << i << "]" << "[" << j << "]: "; 
			std::cin >> matrix[i][j]; 
		}
	}

	return matrix;
}

void printVector(double *vector, int length) {
	for (int i = 0; i < length; i++) {
		std::cout << vector[i] << " ";
	}
	std::cout << std::endl;
}

void printMatrix(double **matrix, MatrixDimensions dimensions) {
	for (int i = 0; i < dimensions.getHeight(); i++, std::cout << std::endl) {
		for (int j = 0; j < dimensions.getWidth(); j++) {
			std::cout << std::setw(6) << matrix[i][j];
		}
	}
}

void deleteMatrix(double **matrix, int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        delete [] matrix[i];
    }

    delete [] matrix;
}