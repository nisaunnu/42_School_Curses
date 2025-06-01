#include <ctime>
#include <cstdlib>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXEC), _target("default") {}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", ROBOTOMY_SIGN, ROBOTOMY_EXEC), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
		AForm::operator=(rhs);
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & exec) const
{
	if (!getIsSigned())
		throw AForm::NotSignedException();

	if (exec.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::cout << "* drilling noises *" << std::endl;
	std::srand(std::time(0));

	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << _target << "." << std::endl;
}
