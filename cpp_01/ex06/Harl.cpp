#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << GREEN << std::endl << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
			  << "I really do!"
			  << RESET << std::endl;
}

void	Harl::info()
{
	std::cout << YELLOW << std::endl << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money.\n"
			  << "You didn't put enough bacon in my burger!\n"
			  << "If you did, I wouldn't be asking for more!"
			  << RESET << std::endl;
}

void	Harl::warning()
{
	std::cout << PURPLE << std::endl << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free.\n"
			  << "I've been coming for years whereas you started working here since last month."
			  << RESET << std::endl;
}

void	Harl::error()
{
	std::cout << RED << std::endl << "[ ERROR ]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now.\n"
			  << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	std::size_t	levelNumber = 0;
	std::string commentTypes[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*memberFunctionPointer[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (levelNumber = 0; levelNumber < 4 && commentTypes[levelNumber] != level; levelNumber++)
		;

	switch (levelNumber)
	{
		case 0:
			(this->*memberFunctionPointer[0])();
		case 1:
			(this->*memberFunctionPointer[1])();
		case 2:
			(this->*memberFunctionPointer[2])();
		case 3:
			(this->*memberFunctionPointer[3])();
			break;
		default:
			std::cout << CYAN << std::endl << "[ Probably complaining about insignificant problem ]\n" << RESET << std::endl;
	}
}


