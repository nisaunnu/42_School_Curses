#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

# define RESET     "\033[0m"
# define BLUE      "\033[38;5;45m"

# define HEADER(txt) std::cout << std::endl << BLUE << "-- " << txt << " --" << RESET << std::endl;

template	<typename T>
class Array
{
	private:
	T*				_data;
	unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& rhs);
		Array&	operator=(const Array& rhs);
		~Array();

		T&			operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;

		unsigned int	size() const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
};

template	<typename T>
std::ostream&	operator<<(std::ostream& os, const Array<T>& data);

# include "Array.tpp"

#endif
