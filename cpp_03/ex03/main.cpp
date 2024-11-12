#include "DiamondTrap.hpp"

int main()
{
	std::cout << BLUE << UNDERLINE << "\n>> Creating ClapTrap <<" << RESET << std::endl;
	ClapTrap clap("Clappy");

	std::cout << BLUE << UNDERLINE << "\n>> ClapTrap Attacks <<" << RESET << std::endl;
	clap.attack("Target 1");

	std::cout << BLUE << UNDERLINE << "\n>> ClapTrap Takes Damage and Repairs <<" << RESET << std::endl;
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << BLUE << UNDERLINE << "\n>> Creating ScavTrap <<" << RESET << std::endl;
	ScavTrap scav("Guardian");

	std::cout << BLUE << UNDERLINE << "\n>> ScavTrap Attacks and Guard Mode <<" << RESET << std::endl;
	scav.attack("Target 2");
	scav.guardGate();

	std::cout << BLUE << UNDERLINE << "\n>> Creating FragTrap <<" << RESET << std::endl;
	FragTrap frag("Fragger");

	std::cout << BLUE << UNDERLINE << "\n>> FragTrap Attacks and Requests High Five <<" << RESET << std::endl;
	frag.attack("Target 3");
	frag.highFivesGuys();

	std::cout << BLUE << UNDERLINE << "\n>> Creating DiamondTrap <<" << RESET << std::endl;
	DiamondTrap diamond("Diamond");

	std::cout << BLUE << UNDERLINE << "\n>> DiamondTrap Attacks and WhoAmI <<" << RESET << std::endl;
	diamond.attack("Target 4");
	diamond.whoAmI();

	std::cout << BLUE << UNDERLINE << "\n>> Program Ends (Destructors Called) <<" << RESET << std::endl;
	return 0;
}