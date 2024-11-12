#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# define RESET     "\033[0m"
# define GREEN     "\033[38;5;40m"
# define BLUE      "\033[38;5;39m"
# define PURPLE    "\033[38;5;183m"
# define RED       "\033[38;5;203m"
# define GOLD      "\033[38;5;220m"

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);
		virtual			~WrongAnimal();

		std::string		getType() const;
		virtual void	makeSound() const;
};

#endif
