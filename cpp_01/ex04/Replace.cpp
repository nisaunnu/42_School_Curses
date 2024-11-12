#include "Replace.hpp"

int	printMessage(std::string message)
{
	if (message.compare("ARG"))
		std::cerr << RED << "\nError: Number of arguments is incorrect" << std::endl
				  << "Usage: ./replace <filename> <string1> <string2>" << RESET << std::endl << std::endl;
	else if (message.compare("EMPTY"))
		std::cerr << RED << "\nError: First string cannot be empty" << RESET << std::endl << std::endl;
	else if(message.compare("SAME"))
		std::cerr << RED << "\nError: Strings are the same" << RESET << std::endl << std::endl;
	else if (message.compare("INPUT_FILE"))
		std::cerr << RED << "\nError: could not open file" << RESET << std::endl << std::endl;
	else if (message.compare("OUTPUT_FILE"))
		std::cerr << RED << "\nError: could not create output file" << RESET << std::endl << std::endl;
	return (1);
}

int	Replace::replaceManager(std::string filename, std::string s1, std::string s2)
{
	std::string	line;
	std::ifstream in_file(filename);
	std::ofstream out_file(filename + ".replace");

	if (!in_file.is_open())
		return printMessage("INPUT_FILE");

	if (!out_file.is_open())
		return printMessage("OUTPUT_FILE");

	while (std::getline(in_file, line))
	{
		std::size_t	pos = 0;

		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
		}
		out_file << line << std::endl;
	}

	in_file.close();
	out_file.close();

	return 0;
}
