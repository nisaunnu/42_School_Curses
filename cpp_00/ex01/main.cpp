#include <iostream>
#include "PhoneBook.hpp"

void	intro(void)
{
	std::cout << GREEN << "---------------------------------------------" << std::endl << std::endl;
	std::cout << GREEN << " Welcome to the PhoneBook!" << std::endl << std::endl;
	std::cout << YELLOW << "Commands available: " << std::endl;
	std::cout << YELLOW << "  • ADD    : Register a new person" << std::endl;
	std::cout << YELLOW << "  • SEARCH : View a specific person" << std::endl;
	std::cout << YELLOW << "  • EXIT   : Close the program" << std::endl << std::endl;
	std::cout << GREEN << "---------------------------------------------" << std::endl << std::endl << RESET;
}

int	main (void)
{
	PhoneBook	phone_book;
	std::string command;

	phone_book.setIndex(0);

	std::cout << "\033[2J\033[H";
	intro();
	while (true)
	{
		std::cout << CYAN << "Enter a command : " << RESET;
		std::getline(std::cin, command);
		std::cout << std::endl;

		if (command.compare("ADD") == 0)
			phone_book.comAdd();
		else if (command.compare("SEARCH") == 0)
			phone_book.comSearch();
		else if (command.compare("EXIT") == 0)
			break;
		else
			std::cout << "Invalid command" << std::endl;
		std::cout << std::endl;
	}
	return 0;
}
