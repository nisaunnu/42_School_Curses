#include "PmergeMe.hpp"
#include <stdexcept>
#include <limits>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { (void)other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) { (void)other; return *this; }


void	PmergeMe::swapVector(std::vector<int>& vec, int i, int j) 
{
	int	tmp = vec[i];
	vec[i] = vec[j];
	vec[j] = tmp;
}

void	PmergeMe::swapDeque(std::deque<int>& deq, int i, int j) 
{
	int	tmp = deq[i];
	deq[i] = deq[j];
	deq[j] = tmp;
}

void	PmergeMe::insertInSortedVector(std::vector<int>& vec, int value) 
{
	int	i = (int)vec.size() - 1;

	vec.push_back(value);

	while (i >= 0 && vec[i] > value) 
    {
		vec[i + 1] = vec[i];
		i--;
	}
	vec[i + 1] = value;
}

void	PmergeMe::insertInSortedDeque(std::deque<int>& deq, int value) 
{
	int i = (int)deq.size() - 1;

	deq.push_back(value);

	while (i >= 0 && deq[i] > value) 
    {
		deq[i + 1] = deq[i];
		i--;
	}
	deq[i + 1] = value;
}

void	PmergeMe::insertionSortVector(std::vector<int>& vec, int start, int end) 
{
	for (int i = start + 1; i <= end; ++i) 
    {
		int	key = vec[i];
		int	j = i - 1;

		while (j >= start && vec[j] > key) 
        {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = key;
	}
}

void	PmergeMe::insertionSortDeque(std::deque<int>& deq, int start, int end) 
{
	for (int i = start + 1; i <= end; ++i) 
	{
		int	key = deq[i];
		int	j = i - 1;

		while (j >= start && deq[j] > key) 
		{
			deq[j + 1] = deq[j];
			j--;
		}
		deq[j + 1] = key;
	}
}

void	PmergeMe::fordJohnsonVector(std::vector<int>& vec) 
{
	int	n = (int)vec.size();

	if (n <= 1)
		return;
	if (n <= 5) 
	{
		insertionSortVector(vec, 0, n - 1);
		return;
	}

	// Step 1: Pair elements and swap to ensure smaller first
	for (int i = 0; i + 1 < n; i += 2) {
		if (vec[i] > vec[i + 1])
			swapVector(vec, i, i + 1);
	}

	// Step 2: Recursively sort the bigger elements (second in each pair)
	std::vector<int>	bigs;

	for (int i = 1; i < n; i += 2)
		bigs.push_back(vec[i]);
	fordJohnsonVector(bigs);

	// Step 3: Merge small elements with sorted big elements
	std::vector<int>	result;
	int					bigIndex = 0;

	// Insert first big element
	result.push_back(bigs[bigIndex++]);

	// Insert smaller elements into sorted result using insertion
	for (int i = 0; i < n; i += 2) 
	{
		int	small = vec[i];
		// Insert small in sorted order into result
		int	j = (int)result.size() - 1;

		result.push_back(0);
		while (j >= 0 && result[j] > small) 
		{
			result[j + 1] = result[j];
			j--;
		}
		result[j + 1] = small;

		// Insert next big if any
		if (bigIndex < (int)bigs.size()) 
		{
			int	big = bigs[bigIndex++];
			j = (int)result.size() - 1;

			result.push_back(0);
			while (j >= 0 && result[j] > big) 
			{
				result[j + 1] = result[j];
				j--;
			}
			result[j + 1] = big;
		}
	}

	// If odd number of elements, last one wasn't paired - insert it
	if (n % 2 != 0) 
	{
		int	last = vec[n - 1];
		int	j = (int)result.size() - 1;
		
		result.push_back(0);
		while (j >= 0 && result[j] > last) 
		{
			result[j + 1] = result[j];
			j--;
		}
		result[j + 1] = last;
	}

	vec = result; // copy sorted result back
}

void	PmergeMe::fordJohnsonDeque(std::deque<int>& deq) 
{
	int	n = (int)deq.size();

	if (n <= 1)
		return;
	if (n <= 5) 
	{
		insertionSortDeque(deq, 0, n - 1);
		return;
	}

	// Step 1: Pair elements and swap to ensure smaller first
	for (int i = 0; i + 1 < n; i += 2) 
	{
		if (deq[i] > deq[i + 1])
			swapDeque(deq, i, i + 1);
	}

	// Step 2: Recursively sort the bigger elements (second in each pair)
	std::deque<int>	bigs;
	for (int i = 1; i < n; i += 2)
		bigs.push_back(deq[i]);
	fordJohnsonDeque(bigs);

	// Step 3: Merge small elements with sorted big elements
	std::deque<int>	result;
	int bigIndex = 0;

	// Insert first big element
	result.push_back(bigs[bigIndex++]);

	// Insert smaller elements into sorted result using insertion
	for (int i = 0; i < n; i += 2) 
	{
		int	small = deq[i];
		int	j = (int)result.size() - 1;

		result.push_back(0);
		while (j >= 0 && result[j] > small) 
		{
			result[j + 1] = result[j];
			j--;
		}
		result[j + 1] = small;

		// Insert next big if any
		if (bigIndex < (int)bigs.size()) 
		{
			int	big = bigs[bigIndex++];
			j = (int)result.size() - 1;

			result.push_back(0);
			while (j >= 0 && result[j] > big) 
			{
				result[j + 1] = result[j];
				j--;
			}
			result[j + 1] = big;
		}
	}

	// If odd number of elements, last one wasn't paired - insert it
	if (n % 2 != 0) 
	{
		int	last = deq[n - 1];
		int	j = (int)result.size() - 1;

		result.push_back(0);
		while (j >= 0 && result[j] > last) 
		{
			result[j + 1] = result[j];
			j--;
		}
		result[j + 1] = last;
	}

	deq = result; // copy sorted result back
}

void	PmergeMe::sortVector(std::vector<int>& container) { fordJohnsonVector(container); }
void	PmergeMe::sortDeque(std::deque<int>& container)   { fordJohnsonDeque(container);  }
