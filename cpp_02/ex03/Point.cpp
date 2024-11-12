#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float xValue, const float yValue) : x(xValue), y(yValue) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::~Point() {}

Point&	Point::operator=( const Point& )
{
	return (*this);
}

Fixed	Point::getX(void) const {return (this->x);}

Fixed	Point::getY(void) const {return (this->y);}
