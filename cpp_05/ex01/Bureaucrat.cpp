#include "Form.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(GRADE_LOW) {}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < GRADE_HIGH)
		throw GradeTooHighException();
	if (grade > GRADE_LOW)
		throw GradeTooLowException();

	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName() const  { return this->_name;  }
int			Bureaucrat::getGrade() const { return this->_grade; }

void	Bureaucrat::gradeDecrement()
{
	if (this->_grade + 1 > GRADE_LOW)
		throw GradeTooLowException();
	this->_grade++;
}

void	Bureaucrat::gradeIncrement()
{
	if (this->_grade - 1 < GRADE_HIGH)
		throw GradeTooHighException();
	this->_grade--;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() { return "Grade is too high!"; }
const char*	Bureaucrat::GradeTooLowException::what() const throw()  { return "Grade is too low!";  }

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return os;
}

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
