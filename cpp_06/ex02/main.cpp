#include <iostream>
#include <cstdlib>
#include <ctime>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "identify.hpp"


int main()
{
	try
	{
		std::srand(static_cast<unsigned int>(std::time(0)));  
		
		for (int i = 0; i < 5; ++i)
		{
			std::cout << "Test " << i + 1 << ":" << std::endl;

			Base* obj = generate();

			std::cout << "Identify by pointer: ";
			identify(obj);

			std::cout << "Identify by reference: ";
			identify(*obj);

			std::cout << "----------------------" << std::endl;

			delete obj;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

		std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "=== TEST 1: dynamic_cast with Pointer ===" << std::endl;
	Base* basePtr = generate();  
	identify(basePtr);          
	delete basePtr;

	std::cout << "\n=== TEST 2: dynamic_cast with Reference ===" << std::endl;
	Base* anotherPtr = generate();
	identify(*anotherPtr);    
	delete anotherPtr;

	std::cout << "\n=== TEST 3: Failed dynamic_cast (pointer) ===" << std::endl;
	Base* base = new Base(); 
	A* a = dynamic_cast<A *>(base);
	if (a == NULL)
		std::cout << "Pointer cast failed (returned nullptr)" << std::endl;
	else
		std::cout << "Pointer cast succeeded" << std::endl;
	delete base;

	std::cout << "\n=== TEST 4: Failed dynamic_cast (reference) ===" << std::endl;
	Base b;
	try {
		A& refA = dynamic_cast<A &>(b); 
		(void)refA;
		std::cout << "Reference cast succeeded" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Reference cast failed: " << e.what() << std::endl;
	}

	return 0;
}
