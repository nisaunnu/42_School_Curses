#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc == 2)
		harl.complain(argv[1]);
	else
		std::cout << ORANGE << std::endl
				  << "Usage  : ./harlFilter <level>\n\n"
				  << "Levels : DEBUG, INFO, WARNING and ERROR"
				  << RESET << std::endl << std::endl;

	return 0;
}
