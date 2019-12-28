#ifndef COMPLEX
#define COMPLEX

#include <iostream>

struct Complex
{
    private:
        double real;
        double imaginary;

    public:
        Complex();
        Complex(double real, double imaginary);
        Complex(const Complex& source);
        double getReal();
        double getImaginary();
        Complex operator+(const Complex &secondOp);
        Complex operator-(const Complex &secondOp);
        Complex operator*(const Complex &secondOp);
        Complex operator/(const Complex &secondOp);
        bool operator==(const Complex &secondOp);
        bool operator<(const Complex &secondOp);
        bool operator>(const Complex &secondOp);
        friend std::ostream &operator<<(std::ostream &output, const Complex &op);
        friend std::istream &operator>>(std::istream &input, Complex &op);
};

#endif