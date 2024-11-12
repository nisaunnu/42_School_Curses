#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointNumber = intValue << Fixed::fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointNumber = roundf(floatValue * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
		this->fixedPointNumber = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	return (this->fixedPointNumber);
}

void	Fixed::setRawBits(int const raw)
{
	this->fixedPointNumber = raw;
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fixedPointNumber) / (1 << Fixed::fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (this->fixedPointNumber >> Fixed::fractionalBits);
}

std::ostream	&operator<< (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}

