#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook(void) : index(0)
{
}

void PhoneBook::setIndex(int index)
{
	this->index = index;
}

void PhoneBook::comAdd()
{
	int temp = index;

	if(index >= 8)
		temp = index % 8;

	std::string fn;
	std::string ln;
	std::string nn;
	std::string pn;
	std::string ds;

	std::cout << "firstname      : ";
	std::getline(std::cin, fn, '\n');
	std::cout << "lastname       : ";
	std::getline(std::cin, ln, '\n');
	std::cout << "nickname       : ";
	std::getline(std::cin, nn, '\n');
	std::cout << "darkest secret : ";
	std::getline(std::cin, ds, '\n');
	std::cout << "phone number   : ";
	std::getline(std::cin, pn, '\n');

	persons[temp].setEverything(fn, ln, nn, pn, ds);
	index++;
}

static std::string shortenString(std::string str)
{
	if (str.length() < 10)
		return (str);
	else
		return (str.substr(0, 10 - 1) + ".");
}

void PhoneBook::comSearch()
{

	if(index == 0)
	{
		std::cout << "Phone book is empty for now." << std::endl;
		return ;
	}

	int userIndex, userTemp = index;

	if(index > 8)
		userTemp = 8;

	std::cout << ORANGE << std::setw(10) << std::right << "Index" << "|";
	std::cout << ORANGE << std::setw(10) << std::right << "Firstname" << "|";
	std::cout << ORANGE << std::setw(10) << std::right << "Lastname" << "|";
	std::cout << ORANGE << std::setw(10) << std::right << "Nickname" << "|" << std::endl;
	std::cout << ORANGE << "----------|----------|----------|----------|" << std::endl << RESET;

	for(int i = 0;i < userTemp; i++)
	{
		std::cout << RESET << std::setw(10) << std::right << i + 1 << ORANGE << "|" ;
		std::cout << RESET << std::setw(10) << std::right << shortenString(persons[i].getFirstName()) << ORANGE << "|";
		std::cout << RESET << std::setw(10) << std::right << shortenString(persons[i].getLastName()) << ORANGE << "|";
		std::cout << RESET << std::setw(10) << std::right << shortenString(persons[i].getNickName()) << ORANGE << "|" << std::endl << RESET;
	}

	while (true)
	{
		std::cout << std::endl << "Enter the number of the person you want to view: ";
		std::cin >> userIndex;

		if (std::cin.fail())
		{
			std::cout << "Invalid input! Please enter a valid integer." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (userIndex < 1 || userIndex > userTemp)
			std::cout << "Invalid index! Please enter a valid index between 1 and " << userTemp << "." << std::endl;
		else
		{
			userIndex--;
			std::cout << std::endl;
			std::cout << "Firstname     : " << persons[userIndex].getFirstName() << std::endl;
			std::cout << "Lastname      : " << persons[userIndex].getLastName() << std::endl;
			std::cout << "Nickname      : " << persons[userIndex].getNickName() << std::endl;
			std::cout << "Phonenumber   : " << persons[userIndex].getPhoneNumber() << std::endl;
			std::cout << "Darkestsecret : " << persons[userIndex].getDarkestSecret() << std::endl;
			std::cin.ignore();
			break;
		}
	}

}
