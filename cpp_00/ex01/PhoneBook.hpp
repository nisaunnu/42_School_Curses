#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define RESET  "\033[0m"
# define GREEN  "\033[38;5;10m"
# define CYAN   "\033[38;5;87m"
# define RED    "\033[38;5;196m"
# define ORANGE "\033[38;5;208m"
# define YELLOW "\033[38;5;228m"

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	persons[8];
		int	index;

	public:
		PhoneBook(void);

		void	comAdd();
		void	setIndex(int);
		void	comSearch();
};

#endif
