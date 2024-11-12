#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Run constructor" << std::endl;
}
xx
Zombie::~Zombie(void)
{
	std::cout << "Run destructor" << std::endl;
}
void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
