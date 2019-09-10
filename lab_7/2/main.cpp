#include <iostream>
#include <iomanip>

int main() {
	int rowCount, columnCount;
	std::cout << "Enter matrix dimensions:" << std::endl;
	std::cin >> rowCount >> columnCount;

	int **matrix = new int*[rowCount];
	for (int i = 0; i < rowCount; i++) {
		matrix[i] = new int[columnCount];
		for (int j = 0; j < columnCount; j++) {
			matrix[i][j] = rand() % 100;
			std::cout << std::setw(4) << matrix[i][j];
		}
		std::cout << std::endl;
	}

	int *maxsInRows = new int[rowCount];
	int *minsInColumns = new int[columnCount];

	for (int i = 0; i < rowCount; i++) {
		maxsInRows[i] = matrix[i][0];
		for (int j = 0; j < columnCount; j++) {
			if (*(*(matrix + i) + j) > maxsInRows[i]) {
				maxsInRows[i] = matrix[i][j];
			}
		}
	}

	for (int i = 0; i < columnCount; i++) {
		minsInColumns[i] = matrix[0][i];
		for (int j = 0; j < rowCount; j++) {
			if (*(*(matrix + j) + i) < minsInColumns[i]) {
				minsInColumns[i] = matrix[j][i];
			}
		}
	}

	std::cout << "Max elements in rows: ";
	for (int i = 0; i < rowCount; i++) {
		std::cout << std::setw(4) << maxsInRows[i];
	}
	std::cout << std::endl << "Min elements in columns: ";
	for (int i = 0; i < columnCount; i++) {
		std::cout << std::setw(4) << minsInColumns[i];
	}
	std::cout << std::endl;
}