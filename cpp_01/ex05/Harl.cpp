#include "Harl.hpp"

void	Harl::debug()
{
	std::cout << GREEN << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << RESET << std::endl;
}

void	Harl::info()
{
	std::cout << YELLOW << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << RESET << std::endl;
}

void	Harl::warning()
{
	std::cout << PINK << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << RESET << std::endl;
}

void	Harl::error()
{
	std::cout << RED << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << RESET << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string commentTypes[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*memberFunctionPointer[4])(void) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

	for (std::size_t i = 0; i < 4; i++)
		if (commentTypes[i] == level)
			return (this->*memberFunctionPointer[i])();

	std::cout << CYAN "[ INVALID ]" << std::endl;
	std::cout << "Invalid complaint. Time to go home, Harl." << RESET << std::endl;
}


