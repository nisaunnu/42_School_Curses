#include "Weapon.hpp"

void	Weapon::setType(const std::string& _type)
{
	this->_type = _type;
}

const std::string& Weapon::getType() const
{
	return (this->_type);
}
