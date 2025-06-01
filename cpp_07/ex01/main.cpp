#include <iostream>
#include "iter.hpp"

int main()
{
	int			ints[]    = {1, 2, 3, 4, 5};
	float		floats[]  = {1.1, 2.2, 3.3};
	double		doubles[] = {4.4, 5.5, 6.6};
	char		chars[]   = {'d', 'r', 'e', 'a', 'm'};
	std::string	strs[]    = {"keep", "moving", "forward"};

	HEADER("Int Array    : ");
	iter(ints, 5, printWithPrefix<int>);
	std::cout << std::endl;

	HEADER("Float Array  : ");
	iter(floats, 3, printWithPrefix<float>);
	std::cout << std::endl;

	HEADER("Double Array : ");
	iter(doubles, 3, printWithPrefix<double>);
	std::cout << std::endl;

	HEADER("Char Array   : ");
	iter(chars, 5, printWithPrefix<char>);
	std::cout << std::endl;

	HEADER("String Array : ");
	iter(strs, 3, printWithPrefix<std::string>);
	std::cout << "\n" << std::endl;

	return 0;
}
