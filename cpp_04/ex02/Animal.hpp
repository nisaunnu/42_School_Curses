#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# define RESET     "\033[0m"
# define GREEN     "\033[38;5;40m"
# define BLUE      "\033[38;5;39m"
# define PURPLE    "\033[38;5;183m"
# define RED       "\033[38;5;203m"
# define GOLD      "\033[38;5;220m"

# include <iostream>

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal();
		AAnimal(const AAnimal& other);
		AAnimal&	operator=(const AAnimal& other);
		virtual	~AAnimal();

		std::string		getType() const;
		virtual void	makeSound() const = 0;
};

#endif
