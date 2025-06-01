#include <iostream>
#include "Array.hpp"

int main()
{
	HEADER("Default Constructor");
	Array<int>	a;
	std::cout << "Size: " << a.size() << std::endl;

	HEADER("Parametric Constructor");
	Array<int>	b(5);
	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i * 10;
	std::cout << "b: " << b << std::endl;

	HEADER("Copy Constructor");
	Array<int>	c(b);
	std::cout << "c (copy of b): " << c << std::endl;

	HEADER("Assignment Operator");
	Array<int>	d;
	d = c;
	std::cout << "d (assigned from c): " << d << std::endl;

	HEADER("Modify Original Array and Show Deep Copy");
	b[0] = 999;
	std::cout << "Modified b : " << b << std::endl;
	std::cout << "Unchanged c: " << c << std::endl;

	HEADER("Const Access Operator[]");
	const Array<int>	e(c);
	std::cout << "e[2]: " << e[2] << std::endl;

	HEADER("Size Function");
	std::cout << "Size of e: " << e.size() << std::endl;

	HEADER("OutOfBoundsException Test");
	try
	{
		std::cout << "Accessing out of bounds index: " << b[999] << std::endl;
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	HEADER("Array<float> Test");
	Array<float> f(3);
	f[0] = 3.14f;
	f[1] = 2.71f;
	f[2] = 1.41f;
	std::cout << "f: " << f << std::endl;

	HEADER("Array<std::string> Test");
	Array<std::string> g(2);
	g[0] = "Hello";
	g[1] = "World";
	std::cout << "g: " << g << std::endl;

	HEADER("Array<char> Test");
	Array<char> h(4);
	h[0] = 'A';
	h[1] = 'B';
	h[2] = 'C';
	h[3] = 'D';
	std::cout << "h: " << h << std::endl;

	return 0;
}
