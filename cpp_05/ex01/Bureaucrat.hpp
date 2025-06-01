#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

# define GRADE_HIGH 1
# define GRADE_LOW  150

# define RESET     "\033[0m"
# define UNDERLINE "\033[4m"
# define GREEN     "\033[38;5;40m"
# define BLUE      "\033[38;5;45m"
# define PURPLE    "\033[38;5;141m"
# define RED       "\033[38;5;203m"
# define GOLD      "\033[38;5;184m"

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat();

		std::string	getName() const;
		int			getGrade() const;

		void	gradeIncrement();
		void	gradeDecrement();

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		void	signForm(Form& form);
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
