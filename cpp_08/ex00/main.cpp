#include <list>
#include <deque>
#include <vector>
#include "easyfind.hpp"

int main()
{
	int	vecValues[] = {1, 2, 3, 4, 5};
	int	lstValues[] = {10, 20, 30, 40};
	int	deqValues[] = {100, 200, 300};

	std::vector<int>	vec;
	std::list<int>		lst;
	std::deque<int>		deq;

	fillContainer(vec, vecValues, 5);
	fillContainer(lst, lstValues, 4);
	fillContainer(deq, deqValues, 3);

	testContainer("std::vector", vec, 3, 99);
	testContainer("std::list", lst, 30, 100);
	testContainer("std::deque", deq, 100, -1);

	return 0;
}
