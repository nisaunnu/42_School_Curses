#include "Bureaucrat.hpp"

int main()
{
	try {
		std::cout << std::endl;
		Bureaucrat b1("Mercury", 2);
		std::cout << GOLD << "\nInformation     : " << b1 << RESET << std::endl;

		b1.gradeIncrement();
		std::cout << BLUE << "After increment : " << b1 << RESET << std::endl;

		b1.gradeIncrement();
	}
	catch (const std::exception& e) {
		std::cerr << PURPLE << "\nException       : " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << std::endl;
		Bureaucrat b2("Mars", 149);
		std::cout << GOLD << "\nInformation     : " << b2 << RESET << std::endl;

		b2.gradeDecrement();
		std::cout << BLUE << "After decrement : " << b2 << RESET << std::endl;

		b2.gradeDecrement();
	}
	catch (const std::exception& e) {
		std::cerr << PURPLE << "\nException       : " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << std::endl;
		Bureaucrat b3;
		std::cout << GOLD << "\nInformation     : " << b3 << RESET << std::endl;

		b3.gradeDecrement();
		std::cout << BLUE << "After decrement : " << b3 << RESET << std::endl;

		b3.gradeDecrement();
	}
	catch (const std::exception& e) {
		std::cerr << PURPLE << "\nException       : " << e.what() << RESET << std::endl;
	}

	try {
		std::cout << std::endl;
		Bureaucrat b4("Earth", 3);
		Bureaucrat b5(b4);
		std::cout << GOLD << "\nInformation (b4) : " << b4 << RESET << std::endl;
		std::cout << GOLD << "Information (b5) : " << b5 << RESET << std::endl;

		b4.gradeDecrement();
		b4.gradeDecrement();
		std::cout << BLUE << "\nAfter b4 decrement (b4) : " << b4 << RESET << std::endl;
		std::cout << BLUE << "After b4 decrement (b5) : " << b5 << RESET << std::endl;

		b5.gradeDecrement();
		std::cout << BLUE << "\nAfter b5 decrement (b4) : " << b4 << RESET << std::endl;
		std::cout << BLUE << "After b5 decrement (b5) : " << b5 << RESET << std::endl;

		b4.gradeIncrement();
		b4.gradeIncrement();
		b4.gradeIncrement();
		std::cout << BLUE << "\nAfter b4 increment (b4) : " << b4 << RESET << std::endl;
		std::cout << BLUE << "After b4 increment (b5) : " << b5 << RESET << std::endl;

		b5.gradeIncrement();
		b5.gradeIncrement();
		b5.gradeIncrement();
		b5.gradeIncrement();
		std::cout << BLUE << "\nAfter b5 increment (b4) : " << b4 << RESET << std::endl;
		std::cout << BLUE << "After b5 increment (b5) : " << b5 << RESET << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << PURPLE << "\nException       : " << e.what() << RESET << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
