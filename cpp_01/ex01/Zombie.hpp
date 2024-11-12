#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define RESET  "\033[0m"
# define GREEN  "\033[38;5;10m"
# define CYAN   "\033[38;5;87m"
# define RED    "\033[38;5;203m"
# define PINK   "\033[38;5;204m"
# define ORANGE "\033[38;5;208m"
# define YELLOW "\033[38;5;228m"

# include <iostream>

class Zombie
{
	private:
		std::string	_name;

	public:
		Zombie(void);
		~Zombie(void);
		void	announce();
		void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
