#include "Animal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << GREEN << "AAnimal default constructor called" << RESET << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << PURPLE << "AAnimal copy constructor called" << RESET << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << GOLD << "AAnimal copy assignment operator called" << RESET << std::endl;
	return (*this);
}

AAnimal::~AAnimal()
{
	std::cout << RED << "AAnimal destructor called" << RESET << std::endl;
}

std::string	AAnimal::getType() const
{
	return (type);
}
