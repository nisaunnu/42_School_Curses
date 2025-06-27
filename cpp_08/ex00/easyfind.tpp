#include <iostream>
#include "easyfind.hpp"

const char*	ValueNotFound::what() const throw()
{
	return "Value not found in container";
}

template	<typename T>
typename T::iterator	easyfind(T& container, int value)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), value);

	if (it == container.end())
		throw ValueNotFound();

	return it;
}

template	<typename Container>
void	fillContainer(Container& container, int values[], int size)
{
	for (int i = 0; i < size; ++i)
		container.push_back(values[i]);
}

template	<typename Container>
void	testContainer(const std::string& name, Container& container, int value1, int value2)
{
	HEADER("Testing " + name);

	try
	{
		typename Container::iterator	it = easyfind(container, value1);
		std::cout << std::endl << "Found " << value1 << " in " << name << ": " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception while searching for " << value1 << " in " << name << ": " << e.what() << std::endl << std::endl;
	}

	try
	{
		typename Container::iterator	it = easyfind(container, value2);
		std::cout << std::endl << "Found " << value2 << " in " << name << ": " << *it << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << "Exception while searching for " << value2 << " in " << name << ": " << e.what() << std::endl << std::endl;
	}
}
