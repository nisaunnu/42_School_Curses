#ifndef FIXED_HPP
# define FIXED_HPP

# define RESET     "\033[0m"
# define UNDERLINE "\033[4m"
# define GREEN     "\033[38;5;40m"
# define BLUE      "\033[38;5;39m"
# define PURPLE    "\033[38;5;183m"
# define RED       "\033[38;5;203m"
# define PINK      "\033[38;5;219m"
# define GOLD      "\033[38;5;220m"

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

};

std::ostream	&operator<< (std::ostream& out, const Fixed& fixed);

#endif
