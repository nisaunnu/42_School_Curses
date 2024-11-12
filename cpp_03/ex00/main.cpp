#include "ClapTrap.hpp"

int main()
{
	ClapTrap clap("clap");

	clap.attack("Target1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	clap.attack("Target2");
	clap.takeDamage(10);
	clap.beRepaired(5);

	return 0;
}
