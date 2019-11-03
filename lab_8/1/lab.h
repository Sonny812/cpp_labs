#include "MatrixDimensions.h"

double vectorLength(double *vector, int length);
double scalarProduct(double *firstVector, double *secondVector, int length);
double* multiplyVectorByNumber(double *vector, int length, double number);
double **multiplyMatrixByNumber(double **matrix, MatrixDimensions dimensions, double number);
double *multiplyMatrixByVector(double **matrix,  double* vector, MatrixDimensions dimensions);

double* generateVector(int length);
double* createVectorFromUserInput(int lenght);

double** generateMatrix(MatrixDimensions dimensions);
double** createMatrixFromUserInput(MatrixDimensions dimensions);

void printVector(double *vector, int length);
void printMatrix(double **matrix, MatrixDimensions dimensions);

void deleteMatrix(double **matrix, int rowCount);