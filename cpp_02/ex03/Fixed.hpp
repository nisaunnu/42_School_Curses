#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		std::int32_t				fixedPointNumber;
		static const std::int32_t	fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(const int intValue);
		Fixed(const float floatValue);
		~Fixed(void);

		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;

		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;

		Fixed	&operator++(void);
		Fixed	&operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		static Fixed&		min(Fixed& lhs, Fixed& rhs);
		static Fixed&		max(Fixed& lhs, Fixed& rhs);
		static const Fixed&	min(const Fixed& lhs, const Fixed& rhs);
		static const Fixed&	max(const Fixed& lhs, const Fixed& rhs);

		Fixed abs() const {
        return (this->fixedPointNumber < 0) ? Fixed(-this->fixedPointNumber) : *this;
    }
};

std::ostream	&operator<< (std::ostream& out, const Fixed& fixed);

#endif
