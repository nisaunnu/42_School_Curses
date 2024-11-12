#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << PURPLE << "Dog copy constructor called" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
		Animal::operator=(other);
	std::cout << GOLD << "Dog copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Dog::~Dog()
{
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "Woof! Woof!" << RESET << std::endl;
}
