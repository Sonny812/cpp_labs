#include "complex.hpp"
#include <iostream>

Complex::Complex()
{
    this->real = 0;
    this->imaginary = 0;
}

Complex::Complex(double real, double imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

Complex::Complex(const Complex &source)
{
    this->real = source.real;
    this->imaginary = source.imaginary;
}

double Complex::getReal()
{
    return this->real;
}

double Complex::getImaginary()
{
    return this->imaginary;
}

Complex Complex::operator+(const Complex &secondOp)
{
    return Complex(this->real + secondOp.real, this->imaginary + secondOp.imaginary);
}

Complex Complex::operator-(const Complex &secondOp)
{
    return Complex(this->real - secondOp.real, this->imaginary - secondOp.imaginary);
}

Complex Complex::operator*(const Complex &secondOp)
{
    double real = this->real * secondOp.real - this->imaginary * secondOp.imaginary;
    double imaginary = this->real * secondOp.imaginary + secondOp.real * this->imaginary;

    return Complex(real, imaginary);
}

Complex Complex::operator/(const Complex &secondOp)
{
    double secondOpRealSq = secondOp.real * secondOp.real;
    double secondOpImaginarySq = secondOp.imaginary * secondOp.imaginary;

    double real = (this->real * secondOp.real + this->imaginary * secondOp.imaginary) / (secondOpRealSq + secondOpImaginarySq);
    double imaginary = (secondOp.real * this->imaginary - this->real * secondOp.imaginary) / (secondOpRealSq + secondOpImaginarySq);

    return Complex(real, imaginary);
}

bool Complex::operator==(const Complex &secondOp)
{
    return this->real == secondOp.real && this->imaginary == secondOp.imaginary;
}

std::ostream &operator<<(std::ostream &output, const Complex &op)
{
    return output << op.real << " + " << op.imaginary << "i";
}

std::istream &operator>>(std::istream &input, Complex &op)
{
    return input >> op.real >> op.imaginary;
}
