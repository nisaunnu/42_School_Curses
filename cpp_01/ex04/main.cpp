#include "Replace.hpp"

int	main(int argc, char **argv)
{
	if (argc != 4)
		return printMessage("ARG");

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
		return printMessage("EMPTY");

	if (s1 == s2)
		return printMessage("SAME");

	Replace		replace(filename, s1, s2);
	std::size_t	value = replace.replaceManager(filename, s1, s2);

	return value;
}
