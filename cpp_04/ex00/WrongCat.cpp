#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << GREEN << "WrongCat default constructor called" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << PURPLE << "WrongCat copy constructor called" << RESET << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
		WrongAnimal::operator=(other);
	std::cout << GOLD << "WrongCat copy assignment operator called" << RESET << std::endl;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << BLUE << "WrongCat makes a wrong sound!" << RESET << std::endl;
}
