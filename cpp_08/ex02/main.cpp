#include <list>
#include <iostream>
#include "MutantStack.hpp"

int main()
{
	{
		HEADER("Test with MutantStack");
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "Top: " << mstack.top() << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		HEADER("Iterating through MutantStack");	
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		HEADER("Reverse iteration");	
		MutantStack<int>::reverse_iterator rit = mstack.rbegin();
		MutantStack<int>::reverse_iterator rite = mstack.rend();
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}

		std::stack<int> s(mstack);
	}

	{
		HEADER("Test with std::list");
		std::list<int> lst;
		lst.push_back(5);
		lst.push_back(17);
		std::cout << "Back: " << lst.back() << std::endl;
		lst.pop_back();
		std::cout << "Size: " << lst.size() << std::endl;
		lst.push_back(3);
		lst.push_back(5);
		lst.push_back(737);
		lst.push_back(0);

		HEADER("Iterating through list");	
		std::list<int>::iterator it = lst.begin();
		std::list<int>::iterator ite = lst.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}

		HEADER("Reverse iteration list");	
		std::list<int>::reverse_iterator rit = lst.rbegin();
		std::list<int>::reverse_iterator rite = lst.rend();
		while (rit != rite)
		{
			std::cout << *rit << std::endl;
			++rit;
		}
	}

	return 0;
}
