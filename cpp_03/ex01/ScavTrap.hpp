#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# define RESET     "\033[0m"
# define UNDERLINE "\033[4m"
# define BLUE      "\033[38;5;39m"

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(const std::string& _name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();

		void attack(const std::string& target);
		void guardGate();
};

#endif
