#ifndef SPAN_HPP
# define SPAN_HPP

# include <limits>
# include <vector>
# include <algorithm>

# define RESET     "\033[0m"
# define BLUE      "\033[38;5;45m"

# define HEADER(txt) std::cout << std::endl << BLUE << "--- " << txt << " ---" << RESET << std::endl;

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span();

		void	addNumber(int number);
		void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void	addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);

		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		class	SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
