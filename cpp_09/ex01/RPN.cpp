#include "RPN.hpp"
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::RPN(const RPN& other) { this->_stack = other._stack; }

RPN& RPN::operator=(const RPN& other) 
{
	if (this != &other)
		this->_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

void	RPN::evaluate(const std::string& expression)
{
	std::string			token;
	std::istringstream	iss(expression);

	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(std::atoi(token.c_str()));
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
				throw RPN::InsufficientOperandsException();

			int	b = _stack.top(); _stack.pop();
			int	a = _stack.top(); _stack.pop();

			if (token == "+")
				_stack.push(a + b);
			else if (token == "-")
				_stack.push(a - b);
			else if (token == "*")
				_stack.push(a * b);
			else if (token == "/")
			{
				if (b == 0)
					throw RPN::DivisionByZeroException();
				_stack.push(a / b);
			}
		}
		else
			throw RPN::InvalidTokenException();
	}

	if (_stack.size() != 1)
		throw RPN::TooManyOperandsException();
}


int	RPN::getResult() const
{
	if (_stack.empty())
		throw RPN::InsufficientOperandsException();
	return _stack.top();
}

const char*	RPN::InvalidTokenException::what() const throw()         { return "Error";                                   }
const char*	RPN::DivisionByZeroException::what() const throw()       { return "Error: Division by zero.";                }
const char*	RPN::TooManyOperandsException::what() const throw()      { return "Error: Too many operands left in stack."; }
const char*	RPN::InsufficientOperandsException::what() const throw() { return "Error: Not enough operands.";             }
