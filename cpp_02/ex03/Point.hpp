#ifndef POINT_HPP
# define POINT_HPP

# define RESET     "\033[0m"
# define UNDERLINE "\033[4m"
# define BLUE      "\033[38;5;39m"
# define PURPLE    "\033[38;5;183m"

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;

	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& );
		Point& operator=(const Point& other);
		~Point();

		Fixed	getX(void) const;
		Fixed	getY(void) const;

		bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
