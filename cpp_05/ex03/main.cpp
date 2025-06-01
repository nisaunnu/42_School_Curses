#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define LINE "\033[38;5;240m------------------------------------------------------------\033[0m"
#define HEADER(txt) std::cout << LINE << "\n" << BLUE << txt << RESET << "\n" << LINE << std::endl;

int main()
{
	HEADER("[TEST] Intern Form Creation and Bureaucrat Execution");

	Intern		intern;
	Bureaucrat	boss("Emre", 1); 

	const std::string formTypes[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	const std::string	target = "OpenAI";

	for (int i = 0; i < 3; ++i)
	{
		std::cout << YELLOW << "\nRequesting form: " << formTypes[i] << RESET << std::endl;
		AForm*	form = intern.makeForm(formTypes[i], target);

		if (form)
		{
			try
			{
				std::cout << GREEN << "\nSigning form..." << RESET << std::endl;
				boss.signForm(*form);

				std::cout << GREEN << "Executing form..." << RESET << std::endl;
				boss.executeForm(*form);
			} catch (const std::exception& e) {
				std::cerr << RED << "[ERROR] " << e.what() << RESET << std::endl;
			}
			delete form;
		}
		else
			std::cout << RED << "Failed to create form!" << RESET << std::endl;
	}

	HEADER("[TEST] Invalid Form Request");

	AForm*	invalidForm = intern.makeForm("alien invasion", "Earth");
	if (!invalidForm)
		std::cout << RED << "Intern could not create the requested form (unknown type).\n" << RESET << std::endl;

	std::cout << LINE << "\n" << GREEN << "[SUCCESS] All tests completed.\n" << RESET << LINE << std::endl;

	return 0;
}
