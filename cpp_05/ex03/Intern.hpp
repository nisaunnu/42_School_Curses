#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& src);
		Intern& operator=(const Intern& rhs);
		~Intern();

		AForm*	makeForm(const std::string& formName, const std::string& target) const;
};

#endif
