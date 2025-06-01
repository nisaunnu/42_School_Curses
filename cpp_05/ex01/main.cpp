#include "Form.hpp"
#include "Bureaucrat.hpp"

void testValidScenario()
{
	std::cout << GREEN << "\n--- Test: Valid Scenario ---" << RESET << std::endl;

	Bureaucrat	mercury("Mercury", 30);
	Form		mars("Mars", 50, 20);

	std::cout << mercury << std::endl;
	std::cout << mars    << std::endl;

	mercury.signForm(mars);
	std::cout << mars << std::endl;
}

void testGradeTooLowToSign()
{
	std::cout << GREEN << "\n--- Test: Grade Too Low to Sign ---" << RESET << std::endl;

	Bureaucrat	saturn("Saturn", 120);
	Form		jupiter("Jupiter", 50, 20);

	std::cout << saturn  << std::endl;
	std::cout << jupiter << std::endl;

	saturn.signForm(jupiter);
	std::cout << jupiter << std::endl;
}

void testGradeTooHighExceptionOnForm()
{
	std::cout << GREEN << "\n--- Test: Grade Too High Exception on Form Creation ---" << RESET << std::endl;

	try {
		Form	invalidForm("Invalid Form", 0, 20);
	} catch (std::exception& e) {
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
}

void testGradeTooLowExceptionOnForm()
{
	std::cout << GREEN << "\n--- Test: Grade Too Low Exception on Form Creation ---" << RESET << std::endl;

	try {
		Form	invalidForm("Invalid Form", 200, 20);
	} catch (std::exception& e) {
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
}

void testIncrementDecrementBureaucrat()
{
	std::cout << GREEN << "\n--- Test: Bureaucrat Increment and Decrement ---" << RESET << std::endl;

	{
		Bureaucrat	testIncrement("testIncrement", 2);
		std::cout << testIncrement << std::endl;

		try {
			testIncrement.gradeIncrement();
			std::cout << testIncrement << std::endl;
			testIncrement.gradeIncrement();
		} catch (std::exception& e){
			std::cerr << "Caught Exception: " << e.what() << std::endl;
		}
	}

	{
		Bureaucrat	testDecrement("testDecrement", 149);
		std::cout << testDecrement << std::endl;

		try {
			testDecrement.gradeDecrement();
			std::cout << testDecrement << std::endl;
			testDecrement.gradeDecrement();
		} catch (std::exception& e) {
			std::cerr << "Caught Exception: " << e.what() << std::endl;
		}
	}
}

void testMultipleFormsAndBureaucrats()
{
	std::cout << GREEN << "\n--- Test: Multiple Forms and Bureaucrats ---" << RESET << std::endl;

	Bureaucrat	bureaucratA("bureaucratA", 20);
	Bureaucrat	bureaucratB("bureaucratB", 80);

	Form	formA("Form A", 50, 25);
	Form	formB("Form B", 90, 70);

	std::cout << formA << std::endl;
	bureaucratB.signForm(formA);
	std::cout << formA << std::endl;
	bureaucratA.signForm(formA);
	std::cout << formA << std::endl;

	std::cout << formB << std::endl;
	bureaucratA.signForm(formB);
	bureaucratB.signForm(formB);
	std::cout << formB << std::endl;
}

void testInvalidBureaucratCreation()
{
	std::cout << GREEN << "\n--- Test: Invalid Bureaucrat Creation ---" << RESET << std::endl;

	try {
		Bureaucrat	invalidBureaucrat("Invalid Bureaucrat", 0);
	} catch (std::exception& e) {
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat	invalidBureaucrat("Invalid Bureaucrat", 200);
	} catch (std::exception& e) {
		std::cerr << "Caught Exception: " << e.what() << std::endl;
	}
}

int main()
{
	std::cout << UNDERLINE << RED << "\n<< BUREAUCRAT & FORM TESTING >>" << RESET << std::endl;

	testValidScenario();
	testGradeTooLowToSign();
	testGradeTooHighExceptionOnForm();
	testGradeTooLowExceptionOnForm();
	testIncrementDecrementBureaucrat();
	testMultipleFormsAndBureaucrats();
	testInvalidBureaucratCreation();

	return 0;
}
