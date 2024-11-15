#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << GREEN << "Cat default constructor called" << RESET << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << PURPLE << "Cat copy constructor called" << RESET << std::endl;
	this->brain = new Brain(*other.brain);
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete (this->brain);
		this->brain = new Brain(*other.brain);
	}
	std::cout << GOLD << "Cat copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << RED << "Cat destructor called" << RESET << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << BLUE << "Meow Meow" << RESET << std::endl;
}

Brain* Cat::getBrain() const
{
	return (this->brain);
}
