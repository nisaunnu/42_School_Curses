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
		~Fixed(void);

		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
