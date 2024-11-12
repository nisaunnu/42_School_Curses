#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	if (this->Name.compare("HeapZombie") == 0)
		std::cout << YELLOW;
	else if (this->Name.compare("StackZombie") == 0)
		std::cout << PINK;
	this->Name = name;
	std::cout << this->Name << " was born" << std::endl;
};

Zombie::~Zombie(void)
{
	if (this->Name.compare("HeapZombie") == 0)
		std::cout << YELLOW;
	else if (this->Name.compare("StackZombie") == 0)
		std::cout << PINK;
	std::cout << this->Name << RESET << " is dead" << std::endl;
};

void	Zombie::announce(void)
{
	std::cout << this->Name << RESET << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


