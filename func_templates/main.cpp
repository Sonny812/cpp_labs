#include <iostream>
#include "complex.hpp"

template <typename T>
void sort(T *b, int length, bool sortAsc = true)
{
	T a;
	auto comparator = [sortAsc](T a, T b) {
		return sortAsc ? b < a : a < b;
	};
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (comparator(b[i], b[j]))
			{
				std::swap(b[i], b[j]);
			}
		}
	}
}

template <typename T>
void print(T *b, int length, bool withNewLine = false)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << b[i] << " ";
		if (withNewLine)
		{
			std::cout << std::endl;
		}
	}
}

int main()
{
	const int size = 10;
	int i, arrInt[size];
	double arrDouble[size];
	char arrChar[size] = {'a', 'z', 's', 'e', 'x', 'a', 'e', 'j', 'b', 'q'};
	std::string arrString[size] = {
		"Hello world!\n",
		"Example string\n",
		"Test 2\n",
		"Test 1\n",
		"test\n",
		"Test\n",
		"String\n",
		"123\n",
		"another string\n",
		"one more string\n"
		"321\n",
	};
	Complex arrComp[size] = {
		Complex(1, 2),
		Complex(5, 2),
		Complex(3, 1),
		Complex(4, 0),
		Complex(12, 1),
		Complex(4, 9),
		Complex(10, 1),
		Complex(11, 1),
		Complex(10, 3),
		Complex(10, 5),
	};
	for (int i = 0; i < size; i++)
	{
		arrInt[i] = rand() % 20;
		arrDouble[i] = rand() % 200 / 10.0;
	}

	sort(arrInt, size, false);
	sort(arrDouble, size);
	sort(arrChar, size);
	sort(arrString, size);
	sort(arrComp, size, false);

	print(arrInt, size);
	std::cout << std::endl;
	print(arrDouble, size);
	std::cout << std::endl;
	print(arrChar, size);
	std::cout << std::endl
			  << std::endl;
	print(arrString, size);
	std::cout << std::endl;
	print(arrComp, size, true);
}