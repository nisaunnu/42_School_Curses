#include "Contact.hpp"

void Contact::setEverything(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->firstName = fn;
	this->lastName = ln;
	this->nickName = nn;
	this->phoneNumber = pn;
	this->darkestSecret = ds;
}

std::string	Contact::getFirstName() const
{
	return this->firstName;
}

std::string	Contact::getLastName() const
{
	return this->lastName;
}

std::string	Contact::getNickName() const
{
	return this->nickName;
}

std::string	Contact::getPhoneNumber() const
{
	return this->phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return this->darkestSecret;
}

