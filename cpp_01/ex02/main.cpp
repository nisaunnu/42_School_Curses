#include <iostream>

int main(void)
{
	std::string	str;

	str = "HI THIS IS BRAIN";

	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << std::endl;
	std::cout << "Address of str       : " << &str << std::endl;
	std::cout << "Address of stringPTR : " << &stringPTR << std::endl;
	std::cout << "Address of stringREF : " << &stringREF << std::endl;

	std::cout << std::endl;
	std::cout << "Value of str         : " << str << std::endl;
	std::cout << "Value of stringPTR   : " << *stringPTR << std::endl;
	std::cout << "Value of stringREF   : " << stringREF << std::endl;

	std::cout << std::endl;
	return 0;
}
