#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(LOW), _gradeToExecute(LOW) {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGH || gradeToExecute < HIGH)
		throw GradeTooHighException();
	if (gradeToSign > LOW || gradeToExecute > LOW)
		throw GradeTooLowException();
	this->_isSigned = false;
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

AForm::~AForm() {}

std::string	AForm::getName() const           { return this->_name;           }
bool		AForm::getIsSigned() const       { return this->_isSigned;       }
int			AForm::getGradeToSign() const    { return this->_gradeToSign;    }
int			AForm::getGradeToExecute() const { return this->_gradeToExecute; }

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char*	AForm::GradeTooHighException::what() const throw() { return "AForm: Grade is too high!";  }
const char*	AForm::GradeTooLowException::what() const throw()  { return "AForm: Grade is too low!";   }
const char*	AForm::NotSignedException::what() const throw()    { return "AForm: Form is not signed!"; }

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << BLUE   << UNDERLINE << ">> AForm Info <<" << RESET << std::endl
	   << PURPLE << "Name             : " << RESET << form.getName() << std::endl
	   << PURPLE << "Signed           : " << RESET << (form.getIsSigned() ? "Yes" : "No") << std::endl
	   << PURPLE << "Grade to Sign    : " << RESET << form.getGradeToSign() << std::endl
	   << PURPLE << "Grade to Execute : " << RESET << form.getGradeToExecute() << std::endl;

	return (os);
}
