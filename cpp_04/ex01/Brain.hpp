#ifndef BRAIN_HPP
# define BRAIN_HPP

# define RESET     "\033[0m"
# define GREEN     "\033[38;5;40m"
# define PURPLE    "\033[38;5;183m"
# define RED       "\033[38;5;203m"
# define GOLD      "\033[38;5;220m"

# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain();
		Brain(const Brain &other);
		Brain	&operator=(const Brain &other);
		~Brain();

		std::string	getIdea(int index) const;
		void		setIdea(int index, const std::string &idea);
};

#endif
