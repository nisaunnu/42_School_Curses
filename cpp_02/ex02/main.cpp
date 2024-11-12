#include "Fixed.hpp"

int main(void)
{
	Fixed		a;
	const Fixed b(Fixed(21.21f) * Fixed(2));

	std::cout << std::endl;
	std::cout << BLUE  << UNDERLINE << ">> Value <<" << RESET << std::endl;
	std::cout << "Initial a  : " << a << std::endl;
	std::cout << "Value of b : " << b << std::endl;

	std::cout << std::endl;
	std::cout << BLUE  << UNDERLINE << ">> Increment Operators <<" << RESET << std::endl;
	std::cout << GREEN << "Increment a (pre-increment)     : " << RESET << ++a << std::endl;
	std::cout << GREEN << "Value of a after pre-increment  : " << RESET << a   << std::endl;
	std::cout << GREEN << "Increment a (post-increment)    : " << RESET << a++ << std::endl;
	std::cout << GREEN << "Value of a after post-increment : " << RESET << a   << std::endl;

	std::cout << std::endl;
	std::cout << BLUE << UNDERLINE << ">> Comparison Operators <<" << RESET << std::endl;
	std::cout << PURPLE << "a < b  : " << RESET << (a < b)  << std::endl;
	std::cout << PURPLE << "a > b  : " << RESET << (a > b)  << std::endl;
	std::cout << PURPLE << "a <= b : " << RESET << (a <= b) << std::endl;
	std::cout << PURPLE << "a >= b : " << RESET << (a >= b) << std::endl;
	std::cout << PURPLE << "a == b : " << RESET << (a == b) << std::endl;
	std::cout << PURPLE << "a != b : " << RESET << (a != b) << std::endl;

	Fixed c = a + b;
	Fixed d = b - a;
	Fixed e = a * b;
	Fixed f = b / a;

	std::cout << std::endl;
	std::cout << BLUE << UNDERLINE << ">> Arithmetic Operators <<" << RESET << std::endl;
	std::cout << RED << "a + b : " << RESET << c << std::endl;
	std::cout << RED << "b - a : " << RESET << d << std::endl;
	std::cout << RED << "a * b : " << RESET << e << std::endl;
	std::cout << RED << "b / a : " << RESET << f << std::endl;

	std::cout << std::endl;
	std::cout << BLUE << UNDERLINE << ">> Decrement Operators <<" << RESET << std::endl;
	std::cout << GOLD << "a before decrement              : " << RESET << a   << std::endl;
	std::cout << GOLD << "Decrement a (pre-decrement)     : " << RESET << --a << std::endl;
	std::cout << GOLD << "Value of a after pre-decrement  : " << RESET << a   << std::endl;
	std::cout << GOLD << "Decrement a (post-decrement)    : " << RESET << a-- << std::endl;
	std::cout << GOLD << "Value of a after post-decrement : " << RESET << a   << std::endl;

	std::cout << std::endl;
	std::cout << BLUE << UNDERLINE << ">> Static & Const min and max Functions <<" << RESET << std::endl;
	std::cout << PINK << "Min of a and b       : " << RESET << Fixed::min(a, b) << std::endl;
	std::cout << PINK << "Max of a and b       : " << RESET << Fixed::max(a, b) << std::endl;
	std::cout << PINK << "Const Max of a and b : " << RESET << Fixed::max(const_cast<const Fixed&>(a), const_cast<const Fixed&>(b)) << std::endl;
	std::cout << PINK << "Const Min of a and b : " << RESET << Fixed::min(const_cast<const Fixed&>(a), const_cast<const Fixed&>(b)) << std::endl;

	std::cout << std::endl;
	return 0;
}
