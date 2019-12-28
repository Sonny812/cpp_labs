#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
	int size;
	double **matrix;
	std::cout << "Enter matrix size: ";
	std::cin >> size;
	matrix = new double*[size];
	for (int i = 0; i < size; i++, std::cout << std::endl) {
		matrix[i] = new double[size];
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 50;
			std::cout << std::setw(5) << matrix[i][j];
		}
	}
	double *c = new double[size];
	int B;
	std::cout << "Input c1 and B" << std::endl;
	std::cin >> c[0] >> B;
	
	std::cout << "Array C: " << c[0] << " ";
	for (int i = 1; i < size; i++) {
		c[i] = c[i-1] + B;
		std::cout << c[i] << ' ';
	}

	std::cout << std::endl;

	double S = 0;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				S += matrix[i][j];
			}
		}
	}

	std::cout << "Sum of elements on main diagonal: " << S << std::endl;
	S /= 2;
	std::cout << "S = " << S << std::endl;

	int P = 1;
	double *X = new double[size];
	
	std::cout << "Array X: ";
	for (int i = 0; i < size; i++) {
		double prod = 1;
		for (int j = 0; j < size; j++) {
			prod *= c[j] / (matrix[i][j] + B * c[i]); 
		}
		X[i] = c[i] * (S * P) - prod;
		std::cout << X[i] << " ";
	}
	std::cout << std::endl;

	double mean, geomMean;
	
	double sum = 0;
	for (int i = 0; i < size; i++) {
		sum += X[i];
	}
	mean = sum / size;

	double prod = 1;
	for (int i = 0; i < size; i++) {
		prod *= X[i];
	}
	geomMean = pow(prod, 1.0 / size);

	std::cout << "Mean: " << mean << std::endl;
	std::cout << "Geometric mean: " << geomMean << std::endl;

}
