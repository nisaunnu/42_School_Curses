#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <stdexcept>

class RPN
{
	private:
		std::stack<int>	_stack;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

		void	evaluate(const std::string& expression);
		int		getResult() const;

		class InvalidTokenException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

		class DivisionByZeroException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

		class InsufficientOperandsException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};

		class TooManyOperandsException : public std::exception 
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
