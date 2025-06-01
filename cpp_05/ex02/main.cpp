#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#define LINE "\033[38;5;240m------------------------------------------------------------\033[0m"

int main()
{
	std::cout << LINE << std::endl;
	std::cout << BLUE << "[TEST] Bureaucrats and Forms Creation" << RESET << std::endl;

	Bureaucrat	highRank("HighRank", 1);
	Bureaucrat	midRank("MidRank", 45);
	Bureaucrat	lowRank("LowRank", 150);

	std::cout << GREEN << highRank << RESET << std::endl;
	std::cout << GREEN << midRank << RESET << std::endl;
	std::cout << GREEN << lowRank << RESET << std::endl;

	ShrubberyCreationForm	shrub("garden");
	PresidentialPardonForm	pardon("Marvin");
	RobotomyRequestForm		robot("robotic human");

	std::cout << LINE << std::endl;
	std::cout << BLUE << "[TEST] Form Signing - Success and Failure Status" << RESET << std::endl;

	lowRank.signForm(shrub);

	midRank.signForm(shrub);
	highRank.signForm(robot);
	highRank.signForm(pardon);

	std::cout << LINE << std::endl;
	std::cout << BLUE << "[TEST] Form Execution - Errors and Successes" << RESET << std::endl;

	try {
		midRank.executeForm(robot);  
	} 
	catch (const std::exception& e) {
		std::cerr << RED << "[ERROR] " << e.what() << RESET << std::endl;
	}
	
	highRank.executeForm(robot);
	midRank.executeForm(shrub);
	highRank.executeForm(pardon);

	std::cout << LINE << std::endl;
	std::cout << GREEN << "[SUCCESS] All tests have been completed." << RESET << std::endl;

	return 0;
}
