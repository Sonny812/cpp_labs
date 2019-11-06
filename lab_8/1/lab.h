#include "MatrixDimensions.h"

double vectorLength(double *vector, int length);
double scalarProduct(double *firstVector, double *secondVector, int length);
double* multiplyVectorByNumber(double *vector, int length, double number);
double** multiplyMatrixByNumber(double **matrix, MatrixDimensions dimensions, double number);
double* multiplyMatrixByVector(double **matrix,  double* vector, MatrixDimensions dimensions);
std::tuple<double**,MatrixDimensions> multiplyMatrixByMatrix(double **firstMatrix, MatrixDimensions firstDimensions, double **secondMatrix, MatrixDimensions secondDimensions);
double** addMatrixToMatrix(double **firstMatrix, double **secondMatrix, MatrixDimensions dimensions);
double findMatrixDeterminant(double **matrix, MatrixDimensions dimensions);

void minor(double **matrix, double **minorMatrix, int size, int row, int column);

double* generateVector(int length);
double* createVectorFromUserInput(int lenght);

double** generateMatrix(MatrixDimensions dimensions);
double** createMatrixFromUserInput(MatrixDimensions dimensions);

void printVector(double *vector, int length);
void printMatrix(double **matrix, MatrixDimensions dimensions);

void deleteMatrix(double **matrix, int rowCount);