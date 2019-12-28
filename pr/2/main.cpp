#include <iostream>


double f(double x) {
	return x * x - 2.25 * x;
}

double F(double x) {
	if (x < 0) {
		return F(x + 1.5);
	} 
	if (x > 1.5) {
		return F(x - 1.5);
	}

	return f(x);
}

int main() {
	double a0, deltaA, an;
	std::cout << "Input a0, da, an:" << std::endl; 
	std::cin >> a0 >> deltaA >> an;

	for (double i = a0; i <= an; i += deltaA, std::cout << std::endl) {
		std::cout << "f(" << i << ")" << " = " << F(i);
	}
}