#ifndef HARL_HPP
# define HARL_HPP

# define RESET  "\033[0m"
# define GREEN  "\033[38;5;10m"
# define CYAN   "\033[38;5;87m"
# define RED    "\033[38;5;203m"
# define PURPLE "\033[38;5;206m"
# define ORANGE "\033[38;5;208m"
# define YELLOW "\033[38;5;228m"

# include <iostream>

class Harl
{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:
		void	complain(std::string level);
};

#endif
