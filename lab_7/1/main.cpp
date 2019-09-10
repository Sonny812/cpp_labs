#include <iostream>

int main() {
	int b = 1;
	int x = 10;
	// int * const a; Needs initialization
	// const int &b; Needs initialization
	int * const a = &b;
	const int &c = b;
	// a = &x; a is read-only
	// c = x; c is read-only
	const int *p = &b;
	//*p = 12; p is read-only
	p = &x;
	p = a;
}