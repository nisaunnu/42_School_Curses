#ifndef REPLACE_HPP
# define REPLACE_HPP

# define RESET  "\033[0m"
# define RED    "\033[38;5;203m"

# include <iostream>
# include <fstream>

class Replace
{
	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;

	public:
		Replace(std::string filename, std::string s1, std::string s2) : _filename(filename), _s1(s1), _s2(s2) {};

		int	replaceManager(std::string filename, std::string s1, std::string s2);
};

int		printMessage(std::string message);

#endif
