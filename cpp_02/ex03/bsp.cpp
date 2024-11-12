#include "Point.hpp"

static Fixed calculateDeterminant2x2(Point const a, Point const b)
{
	return ((a.getX() * b.getY()) - (a.getY() * b.getX()));
}

static Fixed fixedABS(Fixed value)
{
	return ((value < 0) ? (value * -1) : value);
}

static Fixed calculateTriangleArea(Point const a, Point const b, Point const c)
{
	Fixed ab = calculateDeterminant2x2(a, b);
	Fixed bc = calculateDeterminant2x2(b, c);
	Fixed ca = calculateDeterminant2x2(c, a);
	return (fixedABS(((ab + bc + ca) / 2)));
}

bool bsp(Point const a, Point const b, Point const c, Point const p)
{
	Fixed abp = calculateTriangleArea(a, b, p);
	Fixed acp = calculateTriangleArea(a, c, p);
	Fixed bcp = calculateTriangleArea(b, c, p);
	Fixed abc = calculateTriangleArea(a, b, c);

	if (abp != 0 && acp != 0 && bcp != 0)
	{
		if (abp + acp + bcp == abc)
			return (true);
	}
	return (false);
}
