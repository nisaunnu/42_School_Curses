#include "ScavTrap.hpp"

int main()
{
	std::cout << BLUE << UNDERLINE << "\n>> Creating ClapTrap <<" << RESET << std::endl;
	ClapTrap clap("Clappy");

	std::cout << BLUE << UNDERLINE << "\n>> ClapTrap Attacks <<" << RESET << std::endl;
	clap.attack("Target 1");

	std::cout << BLUE << UNDERLINE << "\n>> ClapTrap Takes Damage and Repairs <<" << RESET << std::endl;
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << BLUE << UNDERLINE << "\n>> ClapTrap Attacks Again <<" << RESET << std::endl;
	clap.attack("Target 2");

	std::cout << BLUE << UNDERLINE << "\n>> Creating ScavTrap <<" << RESET << std::endl;
	ScavTrap scav("Scapy");

	std::cout << BLUE << UNDERLINE << "\n>> ScavTrap Attacks <<" << RESET << std::endl;
	scav.attack("Target 3");

	std::cout << BLUE << UNDERLINE << "\n>> ScavTrap Activates Guard Mode <<" << RESET << std::endl;
	scav.guardGate();

	std::cout << BLUE << UNDERLINE << "\n>> ScavTrap Takes Damage and Repairs <<" << RESET << std::endl;
	scav.takeDamage(40);
	scav.beRepaired(20);

	std::cout << BLUE << UNDERLINE << "\n>> ScavTrap Attacks Again <<" << RESET << std::endl;
	scav.attack("Target 4");

	std::cout << BLUE << UNDERLINE << "\n>> Program Ends (Destructors Called) <<" << RESET << std::endl;
	return 0;
}
