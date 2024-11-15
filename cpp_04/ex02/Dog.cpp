#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << GREEN << "Dog default constructor called" << RESET << std::endl;
}

Dog::Dog(const Dog& other) : AAnimal(other), brain(new Brain(*other.brain))
{
	std::cout << PURPLE << "Dog copy constructor called" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		AAnimal::operator=(other);
		delete (this->brain);
		this->brain = new Brain(*other.brain);
	}
	std::cout << GOLD << "Dog copy assignment operator called" << RESET << std::endl;
	return (*this);
}

Dog::~Dog()
{
	delete (this->brain);
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << BLUE << "Woof! Woof!" << RESET << std::endl;
}

Brain* Dog::getBrain() const
{
	return (this->brain);
}
