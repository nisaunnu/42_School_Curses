#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
};

std::ostream	&operator<< (std::ostream& out, const Fixed& fixed);

#endif
