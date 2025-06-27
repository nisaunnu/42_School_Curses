#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <ctime>
# include <deque>
# include <vector>
# include <iostream>

class PmergeMe 
{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		void	sortVector(std::vector<int>& container);
		void	sortDeque(std::deque<int>& container);

	private:
		// Ford-Johnson algorithm implementations
		void	fordJohnsonVector(std::vector<int>& vec);
		void	fordJohnsonDeque(std::deque<int>& deq);

		// Helpers
		void	insertionSortVector(std::vector<int>& vec, int start, int end);
		void	insertionSortDeque(std::deque<int>& deq, int start, int end);

		// Insert element at correct position
		void	insertInSortedVector(std::vector<int>& vec, int value);
		void	insertInSortedDeque(std::deque<int>& deq, int value);

		// Swap helper
		void	swapVector(std::vector<int>& vec, int i, int j);
		void	swapDeque(std::deque<int>& deq, int i, int j);
};

#endif
