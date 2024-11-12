#include "Point.hpp"

int main()
{
	Point a(0, 0);
	Point b(3, 0);
	Point c(0, 3);

	Point insidePoint(1, 1);
	Point outsidePoint(15, 5);
	Point firstPoint(0, 0);
	Point vertexPoint(0, 0);
	Point nearEdgePoint(2.5, 0);

	std::cout << std::endl;
	std::cout << BLUE << UNDERLINE << ">> Testing points with respect to triangle ABC <<" << RESET << std::endl;

	std::cout << PURPLE << "Point inside (5, 5)                 : " << RESET << (bsp(a, b, c, insidePoint)   ? "Inside" : "Outside") << std::endl;
	std::cout << PURPLE << "Point outside (15, 5)               : " << RESET << (bsp(a, b, c, outsidePoint)  ? "Inside" : "Outside") << std::endl;
	std::cout << PURPLE << "Point first (0, 0)                  : " << RESET << (bsp(a, b, c, firstPoint)    ? "Inside" : "Outside") << std::endl;
	std::cout << PURPLE << "Point on vertex (0, 0)              : " << RESET << (bsp(a, b, c, vertexPoint)   ? "Inside" : "Outside") << std::endl;
	std::cout << PURPLE << "Point near edge but inside (2.5, 0) : " << RESET << (bsp(a, b, c, nearEdgePoint) ? "Inside" : "Outside") << std::endl;
	std::cout << std::endl;

	return 0;
}
