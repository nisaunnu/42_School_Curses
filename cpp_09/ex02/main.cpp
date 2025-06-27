#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>

bool	isPositiveInteger(const char* str) 
{
	int	i = 0;

	if (str[0] == '\0')
		return false;

	while (str[i]) 
	{
		if (str[i] < '0' || str[i] > '9')
			return false;
		i++;
	}

	if (i > 1 && str[0] == '0')
		return false;
	return true;
}

int main(int argc, char** argv) 
{
	if (argc < 2) 
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	std::vector<int>	numbers_vec;
	std::deque<int>		numbers_deq;

	for (int i = 1; i < argc; ++i) 
	{
		if (!isPositiveInteger(argv[i])) 
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}

		int	val = std::atoi(argv[i]);

		if (val <= 0) 
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}

		numbers_vec.push_back(val);
		numbers_deq.push_back(val);
	}

	std::cout << "Before:";
	for (size_t i = 0; i < numbers_vec.size(); ++i)
		std::cout << " " << numbers_vec[i];
	std::cout << std::endl;

	PmergeMe	sorter;

	// Sort vector and time it
	clock_t	start_vec = clock();
	sorter.sortVector(numbers_vec);
	clock_t	end_vec = clock();

	// Sort deque and time it
	clock_t	start_deq = clock();
	sorter.sortDeque(numbers_deq);
	clock_t	end_deq = clock();

	// Display after sorting (use vector result)
	std::cout << "After:";
	for (size_t i = 0; i < numbers_vec.size(); ++i)
		std::cout << " " << numbers_vec[i];
	std::cout << std::endl;

	double	time_vec = double(end_vec - start_vec) / CLOCKS_PER_SEC * 1000000;
	double	time_deq = double(end_deq - start_deq) / CLOCKS_PER_SEC * 1000000;

	std::cout.precision(5);
	std::cout << "Time to process a range of " << numbers_vec.size()
			  << " elements with std::vector : " << time_vec << " us" << std::endl;
	std::cout << "Time to process a range of " << numbers_deq.size()
			  << " elements with std::deque : " << time_deq << " us" << std::endl;

	return 0;
}
