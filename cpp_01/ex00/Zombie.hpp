#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# define RESET  "\033[0m"
# define PINK   "\033[38;5;205m"
# define YELLOW "\033[38;5;228m"

# include <iostream>

class Zombie
{
	private:
		std::string	Name;

	public:
		Zombie(std::string);
		~Zombie(void);

		void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
