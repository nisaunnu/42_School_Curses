#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# define RESET     "\033[0m"
# define UNDERLINE "\033[4m"
# define BLUE      "\033[38;5;39m"

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap(const std::string& _name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap& operator=(const DiamondTrap& other);
		~DiamondTrap();

		void attack(const std::string& target);
		void whoAmI();
};

#endif
