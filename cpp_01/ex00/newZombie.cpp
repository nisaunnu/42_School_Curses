#include "Zombie.hpp"

Zombie*	newZombie(std::string name)
{
	std::cout << YELLOW;
	Zombie*	zombie = new Zombie(name);
	return (zombie);
}
