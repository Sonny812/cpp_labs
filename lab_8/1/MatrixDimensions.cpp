#include <iostream>
#include "MatrixDimensions.h"

MatrixDimensions::MatrixDimensions(int height, int width): height(height), width(width) {}

int MatrixDimensions::getHeight() {
	return height;
}

int MatrixDimensions::getWidth() {
	return width;
}

MatrixDimensions MatrixDimensions::createFromUserInput() {
	int height, width;
	std::cout << "Enter matrix dimensions: " << std::endl;
	std::cin >> height >> width;
	
	return MatrixDimensions(height, width);
}