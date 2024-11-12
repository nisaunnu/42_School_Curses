#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << GREEN << "Animal default constructor called" << RESET << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << PURPLE << "Animal copy constructor called" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
		type = other.type;
	std::cout << GOLD << "Animal copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Animal::~Animal()
{
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

std::string	Animal::getType() const
{
	return (type);
}

void	Animal::makeSound() const
{
	std::cout << BLUE << "Animal makes a generic sound!" << RESET << std::endl;
}

