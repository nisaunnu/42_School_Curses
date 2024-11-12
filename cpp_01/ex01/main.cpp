#include "Zombie.hpp"

int	main(int argc, char **argv)
{
	int number;

	if (argc == 1)
	{
		while (true)
		{
			std::cout << std::endl << GREEN << "How many zombies should be created?" << std::endl;
			std::cout << CYAN << "Enter a number: " << RESET;

			std::cin >> number;

			if (std::cin.eof() || std::cin.fail() || number < 0)
			{
				std::cerr << std::endl << YELLOW << "Come on! You have to enter a number. Try again!" << RESET << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			else
				break;
		}
		std::cout << std::endl;

		Zombie* horde = zombieHorde(number, "Zombie");

		for (int i = 0; i < number; ++i)
			horde[i].announce();

		delete[] horde;
		std::cout << std::endl;
	}
	else
		std::cerr << std::endl << RED << "Usage: " << argv[0] << RESET << std::endl << std::endl;
	return 0;
}
