#include "HumanB.hpp"

void HumanB::attack() const
{
	if (weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(const Weapon &weapon)
{
	this->weapon = (Weapon*)&weapon;
}
