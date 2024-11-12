#include "Brain.hpp"

Brain::Brain()
{
	std::cout << GREEN << "Brain default constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << PURPLE << "Brain copy constructor called" << RESET << std::endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		std::cout << GOLD << "Brain copy assignment operator called" << RESET << std::endl;
		for (int i = 0; i < 100; ++i)
			this->ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return (this->ideas[index]);
	return ("");
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}
