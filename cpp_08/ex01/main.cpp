#include <ctime>
#include <vector>
#include <cstdlib>
#include <iostream>
#include "Span.hpp"

int main()
{
	try
	{
		{
			HEADER("Test 1: Basic test from subject");

			Span	sp = Span(5);

			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);

			std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span  : " << sp.longestSpan() << std::endl;
		}

		{
			HEADER("Test 2: Test with 10,000 numbers");

			Span				sp2 = Span(10000);
			std::vector<int>	numbers;

			srand(time(NULL));
			for (int i = 0; i < 10000; ++i)
				numbers.push_back(rand());
			sp2.addRange(numbers.begin(), numbers.end());

			std::cout << "Shortest span : " << sp2.shortestSpan() << std::endl;
			std::cout << "Longest span  : " << sp2.longestSpan() << std::endl;
		}

		{
			HEADER("Test 3: Exception tests");

			Span	sp3 = Span(1);
			sp3.addNumber(42);
			try
			{
				sp3.addNumber(43);
			}
			catch (const std::exception& e)
			{
				std::cout << "Exception caught (sp3) : " << e.what() << std::endl;
			}

			Span	sp4 = Span(1);
			try
			{
				sp4.shortestSpan();
			}
			catch (const std::exception& e)
			{
				std::cout << "Exception caught (sp4) : " << e.what() << std::endl;
			}
		}

		{
			HEADER("Test 4: addRange with const_iterator");

			std::vector<int> tempNumbers;
			tempNumbers.push_back(10);
			tempNumbers.push_back(20);
			tempNumbers.push_back(30);
			tempNumbers.push_back(40);
			tempNumbers.push_back(50);
			const std::vector<int> constNumbers(tempNumbers);

			Span sp5(10);
			sp5.addRange(constNumbers.begin(), constNumbers.end());

			std::cout << "Shortest span : " << sp5.shortestSpan() << std::endl;
			std::cout << "Longest span  : " << sp5.longestSpan() << std::endl;
		}

		{
			HEADER("Test 5: addRange with non-const iterators");

			std::vector<int> modifiableNumbers;
			modifiableNumbers.push_back(100);
			modifiableNumbers.push_back(200);
			modifiableNumbers.push_back(300);
			modifiableNumbers.push_back(400);
			modifiableNumbers.push_back(500);

			modifiableNumbers[2] = 350;

			Span sp6(10);
			sp6.addRange(modifiableNumbers.begin(), modifiableNumbers.end());

			std::cout << "Shortest span : " << sp6.shortestSpan() << std::endl;
			std::cout << "Longest span  : " << sp6.longestSpan() << std::endl;
		}

	}
	catch (const std::exception& e)
	{
		std::cerr << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
