#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", PARDON_SIGN, PARDON_EXEC), _target("default") {}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", PARDON_SIGN, PARDON_EXEC), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target) {}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void	PresidentialPardonForm::execute(const Bureaucrat& exec) const
{
	AForm::execute(exec);
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
