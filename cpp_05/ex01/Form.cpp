#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(LOW), _gradeToExecute(LOW) {}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < HIGH || gradeToExecute < HIGH)
		throw GradeTooHighException();
	if (gradeToSign > LOW || gradeToExecute > LOW)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _isSigned(false), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {}

std::string	Form::getName() const           { return this->_name;           }
bool		Form::getIsSigned() const       { return this->_isSigned;       }
int			Form::getGradeToSign() const    { return this->_gradeToSign;    }
int			Form::getGradeToExecute() const { return this->_gradeToExecute; }

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

const char*	Form::GradeTooHighException::what() const throw() { return "Form: Grade is too high!"; }
const char*	Form::GradeTooLowException::what() const throw()  { return "Form: Grade is too low!";  }

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << BLUE   << UNDERLINE << ">> Form Info <<" << RESET << std::endl
	   << PURPLE << "Name             : " << RESET << form.getName() << std::endl
	   << PURPLE << "Signed           : " << RESET << (form.getIsSigned() ? "Yes" : "No") << std::endl
	   << PURPLE << "Grade to Sign    : " << RESET << form.getGradeToSign() << std::endl
	   << PURPLE << "Grade to Execute : " << RESET << form.getGradeToExecute() << std::endl;

	return (os);
}
