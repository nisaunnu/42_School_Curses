#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern&	Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

typedef	AForm* (*FormCreator)(const std::string& target);

static AForm*	createRobotomy(const std::string& target)     { return new RobotomyRequestForm(target);    }
static AForm*	createShrubbery(const std::string& target)    { return new ShrubberyCreationForm(target);  }
static AForm*	createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	FormCreator creators[3] = {
		&createShrubbery,
		&createRobotomy,
		&createPresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern couldn't find the form: " << formName << std::endl;
	return NULL;
}
