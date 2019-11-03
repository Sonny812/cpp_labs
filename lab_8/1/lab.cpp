#include <iostream>
#include <iomanip>
#include <cmath>
#include <tuple>
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
	double **multipliedMatrix = new double*[dimensions.getWidth()];
	for (int i = 0; i < dimensions.getWidth(); i++) {
		multipliedMatrix[i] = new double[dimensions.getHeight()];
		for (int j = 0; j < dimensions.getHeight(); j++) {
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
			std::cout << std::setw(4) << matrix[i][j];
		}
	}
}

void deleteMatrix(double **matrix, int rowCount) {
    for (int i = 0; i < rowCount; i++) {
        delete [] matrix[i];
    }

    delete [] matrix;
}