#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

# define RESET     "\033[0m"
# define BLUE      "\033[38;5;45m"

# define HEADER(txt) std::cout << std::endl << BLUE << txt << RESET;

template <typename T, typename F>
void	iter(T* array, std::size_t length, F func)
{
	if (!array || length == 0)
		return;

	func(*array);
	iter(array + 1, length - 1, func);
}

template	<typename T>
void	printWithPrefix(const T& val)
{
	std::cout << val << "  ";
}

#endif
