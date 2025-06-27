#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

# define RESET     "\033[0m"
# define BLUE      "\033[38;5;45m"

# define HEADER(txt) std::cout << std::endl << BLUE << "--- " << txt << " ---" << RESET;

class	ValueNotFound : public std::exception
{
	public:
		virtual const char* what() const throw();
};

template	<typename T>
typename T::iterator	easyfind(T& container, int value);

template <typename Container>
void	fillContainer(Container& container, int values[], int size);

template <typename Container>
void	testContainer(const std::string& name, Container& container, int value1, int value2);

# include "easyfind.tpp"

#endif
