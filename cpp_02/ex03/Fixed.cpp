#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0) {}

Fixed::Fixed(const int intValue)
{
	this->fixedPointNumber = intValue << Fixed::fractionalBits;
}

Fixed::Fixed(const float floatValue)
{
	this->fixedPointNumber = roundf(floatValue * (1 << Fixed::fractionalBits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if(this != &other)
		this->fixedPointNumber = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {}

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

bool	Fixed::operator> (const Fixed& rhs) const {return (this->fixedPointNumber > rhs.fixedPointNumber);}
bool	Fixed::operator< (const Fixed& rhs) const {return (this->fixedPointNumber < rhs.fixedPointNumber);}
bool	Fixed::operator>= (const Fixed& rhs) const {return (this->fixedPointNumber >= rhs.fixedPointNumber);}
bool	Fixed::operator<= (const Fixed& rhs) const {return (this->fixedPointNumber <= rhs.fixedPointNumber);}
bool	Fixed::operator== (const Fixed& rhs) const {return (this->fixedPointNumber == rhs.fixedPointNumber);}
bool	Fixed::operator!= (const Fixed& rhs) const {return (this->fixedPointNumber != rhs.fixedPointNumber);}

Fixed	Fixed::operator+ (const Fixed& rhs) const {return (Fixed(this->toFloat() + rhs.toFloat()));}
Fixed	Fixed::operator- (const Fixed& rhs) const {return (Fixed(this->toFloat() - rhs.toFloat()));}
Fixed	Fixed::operator* (const Fixed& rhs) const {return (Fixed(this->toFloat() * rhs.toFloat()));}
Fixed	Fixed::operator/ (const Fixed& rhs) const {return (Fixed(this->toFloat() / rhs.toFloat()));}

Fixed&	Fixed::operator++ (void)
{
	this->fixedPointNumber++;
	return (*this);
}

Fixed&	Fixed::operator-- (void)
{
	this->fixedPointNumber--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->fixedPointNumber++;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->fixedPointNumber--;
	return (temp);
}

Fixed&			Fixed::min(Fixed& lhs, Fixed& rhs) {return (lhs < rhs ? lhs : rhs);}
Fixed&			Fixed::max(Fixed& lhs, Fixed& rhs) {return (lhs > rhs ? lhs : rhs);}
const Fixed&	Fixed::min(const Fixed& lhs, const Fixed& rhs) {return (lhs < rhs ? lhs : rhs);}
const Fixed&	Fixed::max(const Fixed& lhs, const Fixed& rhs) {return (lhs > rhs ? lhs : rhs);}
